// Created on: 1994-12-02
// Created by: Jacques GOUSSARD
// Copyright (c) 1994-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

// NOTE:
// GAB 2019: Copied from BRepBuilderAPI_ModifyShape.cxx, so that some AIS classes does not depends on TKTopAlgo, but rather on TKTopBase

#include <BRepLib_ModifyShape.hxx>
#include <BRepTools_Modification.hxx>
#include <Standard_NoSuchObject.hxx>
#include <Standard_NullObject.hxx>
#include <TopoDS_Shape.hxx>

//=======================================================================
//function : BRepLib_ModifyShape
//purpose  : 
//=======================================================================
BRepLib_ModifyShape::BRepLib_ModifyShape () {}


//=======================================================================
//function : BRepLib_ModifyShape
//purpose  : 
//=======================================================================

BRepLib_ModifyShape::BRepLib_ModifyShape (const TopoDS_Shape& S):
    myModifier(S), myInitialShape(S)
{}


//=======================================================================
//function : BRepLib_ModifyShape
//purpose  : 
//=======================================================================

BRepLib_ModifyShape::BRepLib_ModifyShape
    (const Handle(BRepTools_Modification)& M)
{
myModification = M;
}


//=======================================================================
//function : BRepLib_ModifyShape
//purpose  : 
//=======================================================================

BRepLib_ModifyShape::BRepLib_ModifyShape
    (const TopoDS_Shape& S,
     const Handle(BRepTools_Modification)& M): myModifier(S),myInitialShape(S)
{
  myModification = M;
  DoModif();
}


//=======================================================================
//function : DoModif
//purpose  : 
//=======================================================================

void BRepLib_ModifyShape::DoModif ()
{
  if (myInitialShape.IsNull() || myModification.IsNull()) {
    throw Standard_NullObject();
  }
  myModifier.Perform(myModification);
  if (myModifier.IsDone()) {
    Done();
    myShape = myModifier.ModifiedShape(myInitialShape);
  }
  else {
    NotDone();
  }
}


//=======================================================================
//function : DoModif
//purpose  : 
//=======================================================================

void BRepLib_ModifyShape::DoModif (const TopoDS_Shape& S)
{
  if (!S.IsEqual(myInitialShape) || !IsDone()) {
    myInitialShape = S;
    myModifier.Init(S);
    DoModif();
  }
}


//=======================================================================
//function : DoModif
//purpose  : 
//=======================================================================

void BRepLib_ModifyShape::DoModif (const Handle(BRepTools_Modification)& M)
{
myModification = M;
DoModif();
}


//=======================================================================
//function : DoModif
//purpose  : 
//=======================================================================

void BRepLib_ModifyShape::DoModif (const TopoDS_Shape& S,
                                          const Handle(BRepTools_Modification)& M)
{
myInitialShape = S;
myModifier.Init(S);
myModification = M;
DoModif();
}


//=======================================================================
//function : ModifiedShape
//purpose  : 
//=======================================================================

TopoDS_Shape BRepLib_ModifyShape::ModifiedShape
    (const TopoDS_Shape& S) const
{
  return myModifier.ModifiedShape(S);
}

//=======================================================================
//function : Modified
//purpose  : 
//=======================================================================

const TopTools_ListOfShape& BRepLib_ModifyShape::Modified
    (const TopoDS_Shape& F)
{
  myGenFaces.Clear();
  myGenFaces.Append(myModifier.ModifiedShape(F));
  return myGenFaces;
}
