// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESDimen_FlagNote_HeaderFile
#define _IGESDimen_FlagNote_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESDimen_FlagNote_HeaderFile
#include <Handle_IGESDimen_FlagNote.hxx>
#endif

#ifndef _gp_XYZ_HeaderFile
#include <gp_XYZ.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_IGESDimen_GeneralNote_HeaderFile
#include <Handle_IGESDimen_GeneralNote.hxx>
#endif
#ifndef _Handle_IGESDimen_HArray1OfLeaderArrow_HeaderFile
#include <Handle_IGESDimen_HArray1OfLeaderArrow.hxx>
#endif
#ifndef _IGESData_IGESEntity_HeaderFile
#include <IGESData_IGESEntity.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_IGESDimen_LeaderArrow_HeaderFile
#include <Handle_IGESDimen_LeaderArrow.hxx>
#endif
class IGESDimen_GeneralNote;
class IGESDimen_HArray1OfLeaderArrow;
class Standard_OutOfRange;
class gp_XYZ;
class gp_Pnt;
class IGESDimen_LeaderArrow;


//! defines FlagNote, Type <208> Form <0> <br>
//!          in package IGESDimen <br>
//!          Is label information formatted in different ways <br>
class IGESDimen_FlagNote : public IGESData_IGESEntity {

public:

  
  Standard_EXPORT   IGESDimen_FlagNote();
  //! This method is used to set the fields of the class <br>
//!           FlagNote <br>
//!       - leftCorner  : Lower left corner of the Flag <br>
//!       - anAngle     : Rotation angle in radians <br>
//!       - aNote       : General Note Entity <br>
//!       - someLeaders : Leader Entities <br>
  Standard_EXPORT     void Init(const gp_XYZ& leftCorner,const Standard_Real anAngle,const Handle(IGESDimen_GeneralNote)& aNote,const Handle(IGESDimen_HArray1OfLeaderArrow)& someLeaders) ;
  //! returns Lower Left coordinate of Flag as Pnt from package gp <br>
  Standard_EXPORT     gp_Pnt LowerLeftCorner() const;
  //! returns Lower Left coordinate of Flag as Pnt from package gp <br>
//! after Transformation. <br>
  Standard_EXPORT     gp_Pnt TransformedLowerLeftCorner() const;
  //! returns Rotation angle in radians <br>
  Standard_EXPORT     Standard_Real Angle() const;
  //! returns General Note Entity <br>
  Standard_EXPORT     Handle_IGESDimen_GeneralNote Note() const;
  //! returns number of Arrows (Leaders) or zero <br>
  Standard_EXPORT     Standard_Integer NbLeaders() const;
  //! returns Leader Entity <br>
//! raises exception if Index <= 0 or Index > NbLeaders() <br>
  Standard_EXPORT     Handle_IGESDimen_LeaderArrow Leader(const Standard_Integer Index) const;
  //! returns Height computed by the formula : <br>
//! Height = 2 * CH   where CH is from theNote <br>
  Standard_EXPORT     Standard_Real Height() const;
  //! returns the Character Height (from General Note) <br>
  Standard_EXPORT     Standard_Real CharacterHeight() const;
  //! returns Length computed by the formula : <br>
//! Length = TW + 0.4*CH  where CH is from theNote <br>
//!                         and TW is from theNote <br>
  Standard_EXPORT     Standard_Real Length() const;
  //! returns the Text Width (from General Note) <br>
  Standard_EXPORT     Standard_Real TextWidth() const;
  //! returns TipLength computed by the formula : <br>
//! TipLength = 0.5 * H / tan 35(deg)  where H is Height() <br>
  Standard_EXPORT     Standard_Real TipLength() const;




  DEFINE_STANDARD_RTTI(IGESDimen_FlagNote)

protected:




private: 


gp_XYZ theLowerLeftcorner;
Standard_Real theAngle;
Handle_IGESDimen_GeneralNote theNote;
Handle_IGESDimen_HArray1OfLeaderArrow theLeaders;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif