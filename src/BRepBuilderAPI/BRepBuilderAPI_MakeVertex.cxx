// Created on: 1993-07-23
// Created by: Remi LEQUETTE
// Copyright (c) 1993-1999 Matra Datavision
// Copyright (c) 1999-2012 OPEN CASCADE SAS
//
// The content of this file is subject to the Open CASCADE Technology Public
// License Version 6.5 (the "License"). You may not use the content of this file
// except in compliance with the License. Please obtain a copy of the License
// at http://www.opencascade.org and read it completely before using this file.
//
// The Initial Developer of the Original Code is Open CASCADE S.A.S., having its
// main offices at: 1, place des Freres Montgolfier, 78280 Guyancourt, France.
//
// The Original Code and all software distributed under the License is
// distributed on an "AS IS" basis, without warranty of any kind, and the
// Initial Developer hereby disclaims all such warranties, including without
// limitation, any warranties of merchantability, fitness for a particular
// purpose or non-infringement. Please see the License for the specific terms
// and conditions governing the rights and limitations under the License.



#include <BRepBuilderAPI_MakeVertex.ixx>
#include <BRepBuilderAPI.hxx>
#include <BRep_Builder.hxx>
#include <TopoDS.hxx>

//=======================================================================
//function : BRepBuilderAPI_MakeVertex
//purpose  : 
//=======================================================================

BRepBuilderAPI_MakeVertex::BRepBuilderAPI_MakeVertex(const gp_Pnt& P)
: myMakeVertex(P)
{
  if ( myMakeVertex.IsDone()) {
    Done();
    myShape = myMakeVertex.Shape();
  }
}


//=======================================================================
//function : Vertex
//purpose  : 
//=======================================================================

const TopoDS_Vertex&  BRepBuilderAPI_MakeVertex::Vertex()const 
{
  return myMakeVertex.Vertex();
}


//=======================================================================
//function : operator
//purpose  : 
//=======================================================================


BRepBuilderAPI_MakeVertex::operator TopoDS_Vertex() const
{
  return Vertex();
}
