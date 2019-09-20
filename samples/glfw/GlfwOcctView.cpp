// Copyright (c) 2019 OPEN CASCADE SAS
//
// This file is part of the examples of the Open CASCADE Technology software library.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE

#include "GlfwOcctView.h"

#include <AIS_Shape.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <Message.hxx>
#include <Message_Messenger.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <TopAbs_ShapeEnum.hxx>

#include <iostream>

#include <GLFW/glfw3.h>

// ================================================================
// Function : GlfwOcctView
// Purpose  :
// ================================================================
GlfwOcctView::GlfwOcctView()
: myCurAction3d (CurAction3d_Nothing),
  myToRedraw (true)
{
}

// ================================================================
// Function : ~GlfwOcctView
// Purpose  :
// ================================================================
GlfwOcctView::~GlfwOcctView()
{
}

// ================================================================
// Function : toView
// Purpose  :
// ================================================================
GlfwOcctView* GlfwOcctView::toView (GLFWwindow* theWin)
{
  return static_cast<GlfwOcctView*>(glfwGetWindowUserPointer (theWin));
}

// ================================================================
// Function : errorCallback
// Purpose  :
// ================================================================
void GlfwOcctView::errorCallback (int theError, const char* theDescription)
{
  Message::DefaultMessenger()->Send (TCollection_AsciiString ("Error") + theError + ": " + theDescription, Message_Fail);
}

// ================================================================
// Function : run
// Purpose  :
// ================================================================
void GlfwOcctView::run()
{
  initWindow (800, 600, "glfw occt");
  initViewer();
  initDemoScene();
  if (myView.IsNull())
  {
    return;
  }

  myView->MustBeResized();
  myOcctWindow->Map();
  mainloop();
  cleanup();
}

// ================================================================
// Function : initWindow
// Purpose  :
// ================================================================
void GlfwOcctView::initWindow (int theWidth, int theHeight, const char* theTitle)
{
  glfwSetErrorCallback (GlfwOcctView::errorCallback);
  glfwInit();
  const bool toAskCoreProfile = true;
  if (toAskCoreProfile)
  {
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
#if defined (__APPLE__)
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }
  myOcctWindow = new GlfwOcctWindow (theWidth, theHeight, theTitle);
  glfwSetWindowUserPointer       (myOcctWindow->getGlfwWindow(), this);
  // window callback
  glfwSetWindowSizeCallback      (myOcctWindow->getGlfwWindow(), GlfwOcctView::onResizeCallback);
  glfwSetFramebufferSizeCallback (myOcctWindow->getGlfwWindow(), GlfwOcctView::onFBResizeCallback);
  // mouse callback
  glfwSetScrollCallback          (myOcctWindow->getGlfwWindow(), GlfwOcctView::onMouseScrollCallback);
  glfwSetMouseButtonCallback     (myOcctWindow->getGlfwWindow(), GlfwOcctView::onMouseButtonCallback);
  glfwSetCursorPosCallback       (myOcctWindow->getGlfwWindow(), GlfwOcctView::onMouseMoveCallback);
}

// ================================================================
// Function : initViewer
// Purpose  :
// ================================================================
void GlfwOcctView::initViewer()
{
  if (myOcctWindow.IsNull()
   || myOcctWindow->getGlfwWindow() == nullptr)
  {
    return;
  }

  Handle(OpenGl_GraphicDriver) aGraphicDriver = new OpenGl_GraphicDriver (myOcctWindow->GetDisplay(), false);
  Handle(V3d_Viewer) aViewer = new V3d_Viewer (aGraphicDriver);
  aViewer->SetDefaultLights();
  aViewer->SetLightOn();
  aViewer->SetDefaultTypeOfView (V3d_PERSPECTIVE);
  aViewer->ActivateGrid (Aspect_GT_Rectangular, Aspect_GDM_Lines);
  myView = aViewer->CreateView();
  myView->SetImmediateUpdate (false);
  myView->SetWindow (myOcctWindow, myOcctWindow->NativeGlContext());
  myView->ChangeRenderingParams().ToShowStats = true;
  myContext = new AIS_InteractiveContext (aViewer);
}

// ================================================================
// Function : initDemoScene
// Purpose  :
// ================================================================
void GlfwOcctView::initDemoScene()
{
  if (myContext.IsNull())
  {
    return;
  }

  myView->TriedronDisplay (Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_WIREFRAME);

  gp_Ax2 anAxis;
  anAxis.SetLocation (gp_Pnt (0.0, 0.0, 0.0));
  Handle(AIS_Shape) aBox = new AIS_Shape (BRepPrimAPI_MakeBox (anAxis, 50, 50, 50).Shape());
  myContext->Display (aBox, AIS_Shaded, 0, false);
  anAxis.SetLocation (gp_Pnt (25.0, 125.0, 0.0));
  Handle(AIS_Shape) aCone = new AIS_Shape (BRepPrimAPI_MakeCone (anAxis, 25, 0, 50).Shape());
  myContext->Display (aCone, AIS_Shaded, 0, false);

  TCollection_AsciiString aGlInfo;
  {
    TColStd_IndexedDataMapOfStringString aRendInfo;
    myView->DiagnosticInformation (aRendInfo, Graphic3d_DiagnosticInfo_Basic);
    for (TColStd_IndexedDataMapOfStringString::Iterator aValueIter (aRendInfo); aValueIter.More(); aValueIter.Next())
    {
      if (!aGlInfo.IsEmpty()) { aGlInfo += "\n"; }
      aGlInfo += TCollection_AsciiString("  ") + aValueIter.Key() + ": " + aValueIter.Value();
    }
  }
  Message::DefaultMessenger()->Send (TCollection_AsciiString("OpenGL info:\n") + aGlInfo, Message_Info);
}

// ================================================================
// Function : mainloop
// Purpose  :
// ================================================================
void GlfwOcctView::mainloop()
{
  while (!glfwWindowShouldClose (myOcctWindow->getGlfwWindow()))
  {
    // glfwPollEvents() for continuous rendering (immediate return if there are no new events)
    // and glfwWaitEvents() for rendering on demand (something actually happened in the viewer)
    //glfwPollEvents();
    glfwWaitEvents();
    if (!myView.IsNull())
    {
      if (myView->IsInvalidated())
      {
        myView->Redraw();
      }
      else if (myToRedraw)
      {
        myView->RedrawImmediate();
      }
      myToRedraw = false;
    }
  }
}

// ================================================================
// Function : cleanup
// Purpose  :
// ================================================================
void GlfwOcctView::cleanup()
{
  if (!myView.IsNull())
  {
    myView->Remove();
  }
  if (!myOcctWindow.IsNull())
  {
    myOcctWindow->Close();
  }
  glfwTerminate();
}

// ================================================================
// Function : onResize
// Purpose  :
// ================================================================
void GlfwOcctView::onResize (int theWidth, int theHeight)
{
  if (theWidth  != 0
   && theHeight != 0
   && !myView.IsNull())
  {
    myView->Window()->DoResize();
    myView->MustBeResized();
    myView->Invalidate();
    myView->Redraw();
    //myToRedraw = true;
  }
}

// ================================================================
// Function : onMouseScroll
// Purpose  :
// ================================================================
void GlfwOcctView::onMouseScroll (double theOffsetX, double theOffsetY)
{
  if (myView.IsNull()) { return; }

  const Graphic3d_Vec2i aPos = myOcctWindow->CursorPosition();
  myView->StartZoomAtPoint (aPos.x(), aPos.y());
  myView->ZoomAtPoint (0, 0, int(theOffsetY * 4.0), int(theOffsetY * 4.0));
  myView->Invalidate();
  myToRedraw = true;
}

// ================================================================
// Function : onMouseButton
// Purpose  :
// ================================================================
void GlfwOcctView::onMouseButton (int theButton, int theAction, int theMods)
{
  if (myView.IsNull()) { return; }

  const Graphic3d_Vec2i aPos = myOcctWindow->CursorPosition();
  if (theAction != GLFW_PRESS)
  {
    myCurAction3d = CurAction3d_Nothing;
    return;
  }

  myMouseMin = aPos;
  myMouseMax = aPos;
  switch (theButton)
  {
    case GLFW_MOUSE_BUTTON_RIGHT:
    {
      myCurAction3d = CurAction3d_DynamicRoation;
      myView->StartRotation (aPos.x(), aPos.y());
      break;
    }
    case GLFW_MOUSE_BUTTON_MIDDLE:
    {
      myCurAction3d = CurAction3d_DynamicPanning;
      break;
    }
  }
}

// ================================================================
// Function : onMouseMove
// Purpose  :
// ================================================================
void GlfwOcctView::onMouseMove (int thePosX, int thePosY)
{
  if (myView.IsNull()) { return; }

  switch (myCurAction3d)
  {
    case CurAction3d_DynamicRoation:
    {
      myView->Rotation (thePosX, thePosY);
      myView->Invalidate();
      myToRedraw = true;
      break;
    }
    case CurAction3d_DynamicPanning:
    {
      myView->Pan (thePosX - myMouseMax.x(), -(thePosY - myMouseMax.y()));
      myView->Invalidate();
      myToRedraw = true;
      myMouseMax.SetValues (thePosX, thePosY);
      break;
    }
    default:
    {
      myContext->MoveTo (thePosX, thePosY, myView, false);
      myToRedraw = true;
      break;
    }
  }
}
