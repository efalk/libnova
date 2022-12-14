/*
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *  
 *  Copyright (C) 2000 - 2005 Liam Girdwood  
 */

#ifndef _LN_HYPERBOLIC_MOTION_H
#define _LN_HYPERBOLIC_MOTION_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup hyperbolic  Hyperbolic Motion
*
* \brief Functions relating to the Hyperbolic motion of bodies.
*
* Objects which are not confined to the solar system pass through on
* hyperbolic trajectories. The equations used for objects in elliptical
* orbits do not apply to such objects. This module handles these.
*
* All angles are expressed in degrees.
*/

/*! \fn double ln_solve_hyp_barker(double Q1, double G, double t);
* \brief Solve Barkers equation. 
* \ingroup hyperbolic 
*/
double LIBNOVA_EXPORT ln_solve_hyp_barker(double Q1, double G, double t);

/*! \fn double ln_get_hyp_true_anomaly(double q, double e, double t);
* \ingroup hyperbolic
* \brief Calculate the true anomaly. 
*/
double LIBNOVA_EXPORT ln_get_hyp_true_anomaly(double q, double e, double t);

/*! \fn double ln_get_hyp_radius_vector(double q, double e, double t);
* \ingroup hyperbolic
* \brief Calculate the radius vector. 
*/
double LIBNOVA_EXPORT ln_get_hyp_radius_vector(double q, double e, double t);

/*! \fn void ln_get_hyp_geo_rect_posn(struct ln_hyp_orbit *orbit, double JD, struct ln_rect_posn *posn);
* \ingroup hyperbolic
* \brief Calculate an objects rectangular geocentric position.
*/
void LIBNOVA_EXPORT ln_get_hyp_geo_rect_posn(struct ln_hyp_orbit *orbit,
	double JD, struct ln_rect_posn *posn);


/*! \fn void ln_get_hyp_helio_rect_posn(struct ln_hyp_orbit *orbit, double JD, struct ln_rect_posn *posn);
* \ingroup hyperbolic
* \brief Calculate an objects rectangular heliocentric position. 
*/
void LIBNOVA_EXPORT ln_get_hyp_helio_rect_posn(struct ln_hyp_orbit *orbit,
	double JD, struct ln_rect_posn *posn);
	
/*!
* \fn void ln_get_hyp_body_equ_coords(double JD, struct ln_hyp_orbit *orbit, struct ln_equ_posn *posn)
* \ingroup hyperbolic
* \brief Calculate a bodies equatorial coordinates.
*/
void LIBNOVA_EXPORT ln_get_hyp_body_equ_coords(double JD,
	struct ln_hyp_orbit *orbit, struct ln_equ_posn *posn);
	
/*!
* \fn double ln_get_hyp_body_earth_dist(double JD, struct ln_hyp_orbit *orbit)
* \ingroup hyperbolic
* \brief Calculate the distance between a body and the Earth.
*/
double LIBNOVA_EXPORT ln_get_hyp_body_earth_dist(double JD,
	struct ln_hyp_orbit *orbit);

/*!
* \fn double ln_get_hyp_body_solar_dist(double JD, struct ln_hyp_orbit *orbit) 
* \ingroup hyperbolic
* \brief Calculate the distance between a body and the Sun.
*/
double LIBNOVA_EXPORT ln_get_hyp_body_solar_dist(double JD,
	struct ln_hyp_orbit *orbit);

/*! \fn double ln_get_hyp_body_phase_angle(double JD, struct ln_hyp_orbit *orbit);
* \ingroup hyperbolic
* \brief Calculate the phase angle of the body. 
*/
double LIBNOVA_EXPORT ln_get_hyp_body_phase_angle(double JD,
	struct ln_hyp_orbit *orbit);

/*! \fn double ln_get_hyp_body_elong(double JD, struct ln_hyp_orbit *orbit);
* \ingroup hyperbolic
* \brief Calculate the bodies elongation to the Sun. 
*/
double LIBNOVA_EXPORT ln_get_hyp_body_elong(double JD,
	struct ln_hyp_orbit *orbit);

/*! \fn double ln_get_hyp_body_rst(double JD, struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with a hyperbolic orbit.
* \ingroup hyperbolic
*/
int LIBNOVA_EXPORT ln_get_hyp_body_rst(double JD,
	const struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit,
	struct ln_rst_time *rst);

/*! \fn double ln_get_hyp_body_rst_horizon(double JD, struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit, double horizon, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with a hyperbolic orbit.
* \ingroup hyperbolic
*/
int LIBNOVA_EXPORT ln_get_hyp_body_rst_horizon(double JD,
	const struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit,
	double horizon, struct ln_rst_time *rst);

/*! \fn double ln_get_hyp_body_next_rst(double JD, struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an hyperbolic orbit.
* \ingroup hyperbolic
*/
int LIBNOVA_EXPORT ln_get_hyp_body_next_rst(double JD,
	const struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit,
	struct ln_rst_time *rst);

/*! \fn double ln_get_hyp_body_next_rst_horizon(double JD, struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit, double horizon, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an hyperbolic orbit.
* \ingroup hyperbolic
*/
int LIBNOVA_EXPORT ln_get_hyp_body_next_rst_horizon(double JD,
	const struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit,
	double horizon, struct ln_rst_time *rst);

/*! \fn double ln_get_hyp_body_next_rst_horizon_future(double JD, struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit, double horizon, int day_limit, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an hyperbolic orbit.
* \ingroup hyperbolic
*/
int LIBNOVA_EXPORT ln_get_hyp_body_next_rst_horizon_future(double JD,
	const struct ln_lnlat_posn *observer, struct ln_hyp_orbit *orbit,
	double horizon, int day_limit, struct ln_rst_time *rst);

#ifdef __cplusplus
};
#endif

#endif
