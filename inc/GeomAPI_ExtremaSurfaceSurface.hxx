// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _GeomAPI_ExtremaSurfaceSurface_HeaderFile
#define _GeomAPI_ExtremaSurfaceSurface_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
#include <Extrema_ExtSS.hxx>
#include <Handle_Geom_Surface.hxx>
#include <Quantity_Parameter.hxx>
#include <Quantity_Length.hxx>
class Standard_OutOfRange;
class StdFail_NotDone;
class Geom_Surface;
class gp_Pnt;
class Extrema_ExtSS;


//! Describes functions for computing all the extrema
//! between two surfaces.
//! An ExtremaSurfaceSurface algorithm minimizes or
//! maximizes the distance between a point on the first
//! surface and a point on the second surface. Results
//! are start and end points of perpendiculars common to the two surfaces.
//! Solutions consist of pairs of points, and an extremum
//! is considered to be a segment joining the two points of a solution.
//! An ExtremaSurfaceSurface object provides a framework for:
//! -   defining the construction of the extrema,
//! -   implementing the construction algorithm, and
//! -   consulting the results.
//! Warning
//! In some cases, the nearest points between the two
//! surfaces do not correspond to one of the computed
//! extrema. Instead, they may be given by:
//! -   a point of a bounding curve of one surface and one of the following:
//! -   its orthogonal projection on the other surface,
//! -   a point of a bounding curve of the other surface; or
//! -   any point on intersection curves between the two surfaces.
class GeomAPI_ExtremaSurfaceSurface 
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Constructs an empty algorithm for computing
  //! extrema between two surfaces. Use an Init function
  //! to define the surfaces on which it is going to work.
  Standard_EXPORT GeomAPI_ExtremaSurfaceSurface();
  
  //! Computes  the  extrema  distances  between  the
  //! surfaces <S1>  and <S2>
  Standard_EXPORT GeomAPI_ExtremaSurfaceSurface(const Handle(Geom_Surface)& S1, const Handle(Geom_Surface)& S2);
  
  //! Computes  the  extrema  distances  between
  //! the portion of the surface S1 limited by the
  //! two values of parameter (U1min,U1max) in
  //! the u parametric direction, and by the two
  //! values of parameter (V1min,V1max) in the v
  //! parametric direction, and
  //! -   the portion of the surface S2 limited by the
  //! two values of parameter (U2min,U2max) in
  //! the u parametric direction, and by the two
  //! values of parameter (V2min,V2max) in the v
  //! parametric direction.
  Standard_EXPORT GeomAPI_ExtremaSurfaceSurface(const Handle(Geom_Surface)& S1, const Handle(Geom_Surface)& S2, const Quantity_Parameter U1min, const Quantity_Parameter U1max, const Quantity_Parameter V1min, const Quantity_Parameter V1max, const Quantity_Parameter U2min, const Quantity_Parameter U2max, const Quantity_Parameter V2min, const Quantity_Parameter V2max);
  
  //! Initializes this algorithm with the given arguments
  //! and computes  the  extrema  distances  between  the
  //! surfaces <S1>  and <S2>
  Standard_EXPORT   void Init (const Handle(Geom_Surface)& S1, const Handle(Geom_Surface)& S2) ;
  
  //! Initializes this algorithm with the given arguments
  //! and computes  the  extrema  distances  between -
  //! the portion of the surface S1 limited by the two
  //! values of parameter (U1min,U1max) in the u
  //! parametric direction, and by the two values of
  //! parameter (V1min,V1max) in the v parametric direction, and
  //! -   the portion of the surface S2 limited by the two
  //! values of parameter (U2min,U2max) in the u
  //! parametric direction, and by the two values of
  //! parameter (V2min,V2max) in the v parametric direction.
  Standard_EXPORT   void Init (const Handle(Geom_Surface)& S1, const Handle(Geom_Surface)& S2, const Quantity_Parameter U1min, const Quantity_Parameter U1max, const Quantity_Parameter V1min, const Quantity_Parameter V1max, const Quantity_Parameter U2min, const Quantity_Parameter U2max, const Quantity_Parameter V2min, const Quantity_Parameter V2max) ;
  
  //! Returns the number of extrema computed by this algorithm.
  //! Note: if this algorithm fails, NbExtrema returns 0.
  Standard_EXPORT   Standard_Integer NbExtrema()  const;
Standard_EXPORT operator Standard_Integer() const;
  
  //! Returns the points P1 on the first surface and P2 on
  //! the second surface, which are the ends of the
  //! extremum of index Index computed by this algorithm.
  //! Exceptions
  //! Standard_OutOfRange if Index is not in the range [
  //! 1,NbExtrema ], where NbExtrema is the
  //! number of extrema computed by this algorithm.
  Standard_EXPORT   void Points (const Standard_Integer Index, gp_Pnt& P1, gp_Pnt& P2)  const;
  
  //! Returns the parameters (U1,V1) of the point on the
  //! first surface, and (U2,V2) of the point on the second
  //! surface, which are the ends of the extremum of index
  //! Index computed by this algorithm.
  //! Exceptions
  //! Standard_OutOfRange if Index is not in the range [
  //! 1,NbExtrema ], where NbExtrema is the
  //! number of extrema computed by this algorithm.
  Standard_EXPORT   void Parameters (const Standard_Integer Index, Quantity_Parameter& U1, Quantity_Parameter& V1, Quantity_Parameter& U2, Quantity_Parameter& V2)  const;
  
  //! Computes the distance between the end points of the
  //! extremum of index Index computed by this algorithm.
  //! Exceptions
  //! Standard_OutOfRange if Index is not in the range [
  //! 1,NbExtrema ], where NbExtrema is the
  //! number of extrema computed by this algorithm.
  Standard_EXPORT   Quantity_Length Distance (const Standard_Integer Index)  const;
  
  //! Returns the points P1 on the first surface and P2 on
  //! the second surface, which are the ends of the
  //! shortest extremum computed by this algorithm.
  //! Exceptions StdFail_NotDone if this algorithm fails.
  Standard_EXPORT   void NearestPoints (gp_Pnt& P1, gp_Pnt& P2)  const;
  
  //! Returns the parameters (U1,V1) of the point on the
  //! first surface and (U2,V2) of the point on the second
  //! surface, which are the ends of the shortest extremum
  //! computed by this algorithm.
  //! Exceptions - StdFail_NotDone if this algorithm fails.
  Standard_EXPORT   void LowerDistanceParameters (Quantity_Parameter& U1, Quantity_Parameter& V1, Quantity_Parameter& U2, Quantity_Parameter& V2)  const;
  
  //! Computes the distance between the end points of the
  //! shortest extremum computed by this algorithm.
  //! Exceptions StdFail_NotDone if this algorithm fails.
  Standard_EXPORT   Quantity_Length LowerDistance()  const;
Standard_EXPORT operator Standard_Real() const;
  
  //! return the algorithmic object from Extrema
     const  Extrema_ExtSS& Extrema()  const;




protected:





private:



  Standard_Boolean myIsDone;
  Standard_Integer myIndex;
  Extrema_ExtSS myExtSS;


};


#include <GeomAPI_ExtremaSurfaceSurface.lxx>





#endif // _GeomAPI_ExtremaSurfaceSurface_HeaderFile
