// Created on: 1995-06-02
// Created by: Xavier BENVENISTE
// Copyright (c) 1995-1999 Matra Datavision
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

#ifndef _Approx_SameParameter_HeaderFile
#define _Approx_SameParameter_HeaderFile

#include "Adaptor3d_CurveOnSurface.hxx"
#include "Adaptor3d_Surface.hxx"

class Geom_Curve;
class Geom2d_Curve;
class Geom_Surface;

//! Approximation of a  PCurve  on a surface to  make its
//! parameter be the same that the parameter of a given 3d
//! reference curve.
class Approx_SameParameter 
{
public:

  DEFINE_STANDARD_ALLOC

  //! Warning: the C3D and C2D must have the same parametric domain.
  Standard_EXPORT Approx_SameParameter(const Handle(Geom_Curve)& C3D,
                                       const Handle(Geom2d_Curve)& C2D,
                                       const Handle(Geom_Surface)& S,
                                       const Standard_Real Tol);

  //! Warning: the C3D and C2D must have the same parametric domain.
  Standard_EXPORT Approx_SameParameter(const Handle(Adaptor3d_Curve)& C3D,
                                       const Handle(Geom2d_Curve)& C2D,
                                       const Handle(Adaptor3d_Surface)& S,
                                       const Standard_Real Tol);

  //! Warning: the C3D and C2D must have the same parametric domain.
  Standard_EXPORT Approx_SameParameter(const Handle(Adaptor3d_Curve)& C3D,
                                       const Handle(Adaptor2d_Curve2d)& C2D,
                                       const Handle(Adaptor3d_Surface)& S,
                                       const Standard_Real Tol);

  //!@Returns .false. if calculations failed,
  //! .true. if calculations succeed
  Standard_Boolean IsDone() const
  {
    return myDone;
  }

  //!@Returns tolerance (maximal distance) between 3d curve
  //! and curve on surface, generated by 2d curve and surface. 
  Standard_Real TolReached() const
  {
    return myTolReached;
  }

  //! Tells whether the original data had already the same
  //! parameter up to the tolerance : in that case nothing
  //! is done.
  Standard_Boolean IsSameParameter() const
  {
    return mySameParameter;
  }

  //! Returns the 2D curve that has the same parameter as
  //! the 3D curve once evaluated on the surface up to the
  //! specified tolerance.
  Handle(Geom2d_Curve) Curve2d() const
  {
    return myCurve2d;
  }

  //! Returns the 3D curve that has the same parameter as
  //! the 3D curve once evaluated on the surface up to the
  //! specified tolerance.
  Handle(Adaptor3d_Curve) Curve3d() const
  {
    return myC3d;
  }

  //! Returns the 3D curve on surface that has the same parameter as
  //! the 3D curve up to the specified tolerance.
  Handle(Adaptor3d_CurveOnSurface) CurveOnSurface() const
  {
    return myCurveOnSurface;
  }

private:

  //! Internal data structure to unify access to the most actively used data.
  //! This structure is not intended to be class field since
  //! a lot of memory is used in intermediate computations.
  struct Approx_SameParameter_Data
  {
    Adaptor3d_CurveOnSurface myCOnS; // Curve on surface.
    Standard_Integer myNbPnt; // Number of points.
    Standard_Real *myPC3d; // Parameters on 3d curve.
    Standard_Real *myPC2d; // Parameters on 2d curve.

    // Second data arrays. Used in loop over poles.
    Standard_Real *myNewPC3d; // Parameters on 3d curve.
    Standard_Real *myNewPC2d; // Parameters on 2d curve.

    // Parameters ranges.
    Standard_Real myC3dPF; // Curve 3d Parameter First.
    Standard_Real myC3dPL; // Curve 3d Parameter Last.
    Standard_Real myC2dPF; // Curve 2d Parameter First.
    Standard_Real myC2dPL; // Curve 2d Parameter Last.

    Standard_Real myTol; // Working tolerance.

    // Swap data arrays and update number of points.
    void Swap(const Standard_Integer theNewNbPoints)
    {
      myNbPnt = theNewNbPoints;
      Standard_Real * temp;

      // 3-D
      temp = myPC3d;
      myPC3d = myNewPC3d;
      myNewPC3d = temp;

      // 2-D
      temp = myPC2d;
      myPC2d = myNewPC2d;
      myNewPC2d = temp;
    }
  };


  Approx_SameParameter(const Approx_SameParameter &);
  Approx_SameParameter& operator=(const Approx_SameParameter &);

  //! Computes the pcurve (internal use only).
  Standard_EXPORT void Build (const Standard_Real Tol);

  //! Computes initial point distribution.
  Standard_Boolean BuildInitialDistribution(Approx_SameParameter_Data &theData) const;

  //! Increases initial number of samples in case of the C0 continuity.
  //! Return new number of points and corresponding data arrays.
  //@return true if new number of samples is good and false otherwise.
  Standard_Boolean IncreaseInitialNbSamples(Approx_SameParameter_Data &theData) const;

  //! Computes tangents on boundary points.
  //@return true if tangents are not null and false otherwise.
  Standard_Boolean ComputeTangents(const Adaptor3d_CurveOnSurface & theCOnS,
                                   Standard_Real &theFirstTangent,
                                   Standard_Real &theLastTangent) const;

  //! Method to check same parameter state
  //! and build dependency between 2d and 3d curves.
  //@return true if 2d and 3d curves have same parameter state and false otherwise.
  Standard_Boolean CheckSameParameter(Approx_SameParameter_Data &theData,
                                      Standard_Real &theSqDist) const;

  //! Computes interpolated values.
  //!@Returns .false. if computations failed;
  Standard_Boolean Interpolate(const Approx_SameParameter_Data & theData,
                   const Standard_Real aTangFirst,
                   const Standard_Real aTangLast,
                   TColStd_Array1OfReal & thePoles,
                   TColStd_Array1OfReal & theFlatKnots) const;

  //! Increases number of poles in poles loop.
  //@return true if poles is changed and false otherwise.
  Standard_Boolean IncreaseNbPoles(const TColStd_Array1OfReal & thePoles,
                                   const TColStd_Array1OfReal & theFlatKnots,
                                   Approx_SameParameter_Data & theData,
                                   Standard_Real &theBestSqTol) const;

  static const Standard_Integer myNbSamples = 22; // To be consistent with "checkshape".
  static const Standard_Integer myMaxArraySize = 1000;
  const Standard_Real myDeltaMin; // Initialization is allowed only for integral types.

  Standard_Boolean mySameParameter;
  Standard_Boolean myDone;
  Standard_Real myTolReached;
  Handle(Geom2d_Curve) myCurve2d;
  Handle(Adaptor2d_Curve2d) myHCurve2d;
  Handle(Adaptor3d_Curve) myC3d;
  Handle(Adaptor3d_Surface) mySurf;
  Handle(Adaptor3d_CurveOnSurface) myCurveOnSurface;
};

#endif // _Approx_SameParameter_HeaderFile
