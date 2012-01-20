// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface_HeaderFile
#define _StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface_HeaderFile
#include <Handle_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.hxx>
#endif

#ifndef _Handle_StepGeom_QuasiUniformSurface_HeaderFile
#include <Handle_StepGeom_QuasiUniformSurface.hxx>
#endif
#ifndef _Handle_StepGeom_RationalBSplineSurface_HeaderFile
#include <Handle_StepGeom_RationalBSplineSurface.hxx>
#endif
#ifndef _StepGeom_BSplineSurface_HeaderFile
#include <StepGeom_BSplineSurface.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_StepGeom_HArray2OfCartesianPoint_HeaderFile
#include <Handle_StepGeom_HArray2OfCartesianPoint.hxx>
#endif
#ifndef _StepGeom_BSplineSurfaceForm_HeaderFile
#include <StepGeom_BSplineSurfaceForm.hxx>
#endif
#ifndef _StepData_Logical_HeaderFile
#include <StepData_Logical.hxx>
#endif
#ifndef _Handle_TColStd_HArray2OfReal_HeaderFile
#include <Handle_TColStd_HArray2OfReal.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
class StepGeom_QuasiUniformSurface;
class StepGeom_RationalBSplineSurface;
class TCollection_HAsciiString;
class StepGeom_HArray2OfCartesianPoint;
class TColStd_HArray2OfReal;



class StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface : public StepGeom_BSplineSurface {

public:

  //! Returns a QuasiUniformSurfaceAndRationalBSplineSurface <br>
  Standard_EXPORT   StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface();
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Standard_Integer aUDegree,const Standard_Integer aVDegree,const Handle(StepGeom_HArray2OfCartesianPoint)& aControlPointsList,const StepGeom_BSplineSurfaceForm aSurfaceForm,const StepData_Logical aUClosed,const StepData_Logical aVClosed,const StepData_Logical aSelfIntersect) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Standard_Integer aUDegree,const Standard_Integer aVDegree,const Handle(StepGeom_HArray2OfCartesianPoint)& aControlPointsList,const StepGeom_BSplineSurfaceForm aSurfaceForm,const StepData_Logical aUClosed,const StepData_Logical aVClosed,const StepData_Logical aSelfIntersect,const Handle(StepGeom_QuasiUniformSurface)& aQuasiUniformSurface,const Handle(StepGeom_RationalBSplineSurface)& aRationalBSplineSurface) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Standard_Integer aUDegree,const Standard_Integer aVDegree,const Handle(StepGeom_HArray2OfCartesianPoint)& aControlPointsList,const StepGeom_BSplineSurfaceForm aSurfaceForm,const StepData_Logical aUClosed,const StepData_Logical aVClosed,const StepData_Logical aSelfIntersect,const Handle(TColStd_HArray2OfReal)& aWeightsData) ;
  
  Standard_EXPORT     void SetQuasiUniformSurface(const Handle(StepGeom_QuasiUniformSurface)& aQuasiUniformSurface) ;
  
  Standard_EXPORT     Handle_StepGeom_QuasiUniformSurface QuasiUniformSurface() const;
  
  Standard_EXPORT     void SetRationalBSplineSurface(const Handle(StepGeom_RationalBSplineSurface)& aRationalBSplineSurface) ;
  
  Standard_EXPORT     Handle_StepGeom_RationalBSplineSurface RationalBSplineSurface() const;
  
  Standard_EXPORT     void SetWeightsData(const Handle(TColStd_HArray2OfReal)& aWeightsData) ;
  
  Standard_EXPORT     Handle_TColStd_HArray2OfReal WeightsData() const;
  
  Standard_EXPORT     Standard_Real WeightsDataValue(const Standard_Integer num1,const Standard_Integer num2) const;
  
  Standard_EXPORT     Standard_Integer NbWeightsDataI() const;
  
  Standard_EXPORT     Standard_Integer NbWeightsDataJ() const;




  DEFINE_STANDARD_RTTI(StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface)

protected:




private: 


Handle_StepGeom_QuasiUniformSurface quasiUniformSurface;
Handle_StepGeom_RationalBSplineSurface rationalBSplineSurface;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif