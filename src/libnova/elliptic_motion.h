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

#ifndef _LN_ELLIPTIC_MOTION_H
#define _LN_ELLIPTIC_MOTION_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup elliptic  Elliptic Motion
* \brief Functions relating to the elliptic motion of bodies.
*
* See [Orbits](@ref Astronomy) for more information.
*
* All angles are expressed in degrees.
*
* Function | Summary
* ------------- | -------------
* ln_get_ell_mean_anomaly() | Obtain mean anomoly from orbital rate and time
* ln_solve_kepler() | Convert mean anomoly to true anomoly
* ln_get_ell_true_anomaly() | Convert true anomaly to mean anomaly
* ln_get_ell_radius_vector() | Compute radius from semi-major axis, eccentricity, and true anomoly
* ln_get_ell_smajor_diam() | Compute semi-major axis from eccentricity and perihelion
* ln_get_ell_sminor_diam() | Compute semi-minor axis from eccentricity and semi-major axis
* ln_get_ell_mean_motion() | Compute mean daily motion from semi-major axis
* ln_get_ell_geo_rect_posn() | Compute geocentric rectangular coordinates from orbital parameeters and Julian date
* ln_get_ell_helio_rect_posn() | Compute heliocentric rectangular coordinates from orbital parameeters and Julian date
* ln_get_ell_orbit_len() | Compute orbital length from orbital parameeters
* ln_get_ell_orbit_vel() | Compute orbital velocity from orbital parameeters and date
* ln_get_ell_orbit_pvel() | Compute orbital velocity at perihelion from orbital parameeters
* ln_get_ell_orbit_avel() | Compute orbital velocity at aphelion from orbital parameeters
* ln_get_ell_body_phase_angle() | Compute phase of body as seen from Earth
* ln_get_ell_body_elong() | Calculate the body's elongation to the Sun
* ln_get_ell_body_solar_dist() | Calculate the distance between a body and the Sun for the given dater
* ln_get_ell_body_earth_dist() | Calculate the distance between an body and the Earth for the given date
* ln_get_ell_body_equ_coords() | Calculate a body's equatorial coordinates for the given julian day
* ln_get_ell_body_rst() | Calculate the time the rise, set and transit times (if any) of a body
* ln_get_ell_body_rst_horizon() | Same, but arbitrary horizon
* ln_get_ell_body_next_rst() | Calculate next rise, set, and transit times within the next day.
* ln_get_ell_body_next_rst_horizon() | Same, but arbitrary horizon
* ln_get_ell_body_next_rst_horizon_future() | Calculate next rise, set, and transit times
* ln_get_ell_last_perihelion() | Calculate the julian day of the last perihelion
*
*/
	
/*! \fn double ln_solve_kepler(double E, double M);
* \brief Calculate the eccentric anomaly.
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_solve_kepler(double E, double M);

/*! \fn double ln_get_ell_mean_anomaly(double n, double delta_JD);
* \brief Calculate the mean anomaly.
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_get_ell_mean_anomaly(double n, double delta_JD);

/*! \fn double ln_get_ell_true_anomaly(double e, double E);
* \brief Calculate the true anomaly.
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_get_ell_true_anomaly(double e, double E);

/*! \fn double ln_get_ell_radius_vector(double a, double e, double E);
* \brief Calculate the radius vector.
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_get_ell_radius_vector(double a, double e, double E);

/*! \fn double ln_get_ell_smajor_diam(double e, double q);
* \brief Calculate the semi major diameter.
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_get_ell_smajor_diam(double e, double q);

/*! \fn double ln_get_ell_sminor_diam(double e, double a);
* \brief Calculate the semi minor diameter.
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_get_ell_sminor_diam(double e, double a);

/*! \fn double ln_get_ell_mean_motion(double a);
* \brief Calculate the mean daily motion (degrees/day).
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_get_ell_mean_motion(double a);

/*! \fn void ln_get_ell_geo_rect_posn(struct ln_ell_orbit *orbit, double JD, struct ln_rect_posn *posn);
* \brief Calculate the objects rectangular geocentric position. 
* \ingroup elliptic 
*/
void LIBNOVA_EXPORT ln_get_ell_geo_rect_posn(struct ln_ell_orbit *orbit,
	double JD, struct ln_rect_posn *posn);
	
/*! \fn void ln_get_ell_helio_rect_posn(struct ln_ell_orbit *orbit, double JD, struct ln_rect_posn *posn);
* \brief Calculate the objects rectangular heliocentric position. 
* \ingroup elliptic 
*/
void LIBNOVA_EXPORT ln_get_ell_helio_rect_posn(struct ln_ell_orbit *orbit,
	double JD, struct ln_rect_posn *posn);
	
/*! \fn double ln_get_ell_orbit_len(struct ln_ell_orbit *orbit);
* \brief Calculate the orbital length in AU.
* \ingroup elliptic 
*/
double LIBNOVA_EXPORT ln_get_ell_orbit_len(const struct ln_ell_orbit *orbit);

/*! \fn double ln_get_ell_orbit_vel(double JD, struct ln_ell_orbit *orbit);
* \brief Calculate orbital velocity in km/s.
* \ingroup elliptic
*/
double LIBNOVA_EXPORT ln_get_ell_orbit_vel(double JD,
	struct ln_ell_orbit *orbit);

/*! \fn double ln_get_ell_orbit_pvel(struct ln_ell_orbit *orbit);
* \brief Calculate orbital velocity at perihelion in km/s.
* \ingroup elliptic
*/
double LIBNOVA_EXPORT ln_get_ell_orbit_pvel(const struct ln_ell_orbit *orbit);

/*! \fn double ln_get_ell_orbit_avel(struct ln_ell_orbit *orbit);
* \ingroup elliptic
* \brief Calculate the orbital velocity at aphelion in km/s. 
*/
double LIBNOVA_EXPORT ln_get_ell_orbit_avel(const struct ln_ell_orbit *orbit);

/*! \fn double ln_get_ell_body_phase_angle(double JD, struct ln_ell_orbit *orbit);
* \ingroup elliptic
* \brief Calculate the phase angle of the body. The angle Sun - body - Earth. 
*/
double LIBNOVA_EXPORT ln_get_ell_body_phase_angle(double JD,
	struct ln_ell_orbit *orbit);

/*! \fn double ln_get_ell_body_elong(double JD, struct ln_ell_orbit *orbit);
* \ingroup elliptic
* \brief Calculate the bodies elongation to the Sun.. 
*/
double LIBNOVA_EXPORT ln_get_ell_body_elong(double JD,
	struct ln_ell_orbit *orbit);

/*!
* \fn double ln_get_ell_body_solar_dist(double JD, struct ln_ell_orbit *orbit)
* \brief Calculate the distance between a body and the Sun
* \ingroup elliptic
*/
double LIBNOVA_EXPORT ln_get_ell_body_solar_dist(double JD,
	struct ln_ell_orbit *orbit);

/*!
* \fn double ln_get_ell_body_earth_dist(double JD, struct ln_ell_orbit *orbit)
* \brief Calculate the distance between a body and the Earth
* \ingroup elliptic
*/
double LIBNOVA_EXPORT ln_get_ell_body_earth_dist(double JD,
	struct ln_ell_orbit *orbit);

/*!
* \fn void ln_get_ell_body_equ_coords(double JD, struct ln_ell_orbit *orbit, struct ln_equ_posn *posn)
* \brief Calculate a bodies equatorial coords
* \ingroup elliptic
*/
void LIBNOVA_EXPORT ln_get_ell_body_equ_coords(double JD,
	struct ln_ell_orbit *orbit, struct ln_equ_posn *posn);

/*! \fn double ln_get_ell_body_rst(double JD, struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
*/
int LIBNOVA_EXPORT ln_get_ell_body_rst(double JD,
	const struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit,
	struct ln_rst_time *rst);

/*! \fn double ln_get_ell_body_rst_horizon(double JD, struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit, double horizon, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
*/
int LIBNOVA_EXPORT ln_get_ell_body_rst_horizon(double JD,
	const struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit,
	double horizon, struct ln_rst_time *rst);

/*! \fn double ln_get_ell_body_next_rst(double JD, struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
*/
int LIBNOVA_EXPORT ln_get_ell_body_next_rst(double JD,
	const struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit,
	struct ln_rst_time *rst);

/*! \fn double ln_get_ell_body_next_rst_horizon(double JD, struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit, double horizon, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
*/
int LIBNOVA_EXPORT ln_get_ell_body_next_rst_horizon(double JD,
	const struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit,
	double horizon, struct ln_rst_time *rst);

/*! \fn double ln_get_ell_body_next_rst_horizon_future(double JD, struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit, double horizon, int day_limit, struct ln_rst_time *rst);
* \brief Calculate the time of rise, set and transit for a body with an elliptic orbit.
* \ingroup elliptic
*/
int LIBNOVA_EXPORT ln_get_ell_body_next_rst_horizon_future(double JD,
		const struct ln_lnlat_posn *observer, struct ln_ell_orbit *orbit,
		double horizon, int day_limit, struct ln_rst_time *rst);

/*!\fn double ln_get_ell_last_perihelion(double epoch_JD, double M, double n);
* \brief Calculate the julian day of the last perihelion.
* \ingroup elliptic
*/
double LIBNOVA_EXPORT ln_get_ell_last_perihelion(double epoch_JD, double M,
		double n);

#ifdef __cplusplus
};
#endif

#endif
