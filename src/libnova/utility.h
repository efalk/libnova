/**
 * \file
 * \brief Various utility functions
 */

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

#ifndef _LN_UTILITY_H
#define _LN_UTILITY_H

#include <libnova/ln_types.h>

#ifdef __WIN32__
#include <time.h>
// cbrt replacement
#define cbrt(x)   pow(x,1.0/3.0)
#endif // __WIN32__

/* Conversion factors between degrees and radians */
#define D2R  (1.7453292519943295769e-2)  /* deg->radian */
#define R2D  (5.7295779513082320877e1)   /* radian->deg */
#define R2S  (2.0626480624709635516e5)   /* arc seconds per radian */
#define S2R  (4.8481368110953599359e-6)  /* radians per arc second */


#ifdef __cplusplus
extern "C" {
#endif


/*! \defgroup version libnova library version information
*/

/*! \fn char * ln_get_version (void)
* \return Null terminated version string.
*
* Return the libnova library version number string
* e.g. "0.15.0"
*/
const char LIBNOVA_EXPORT *ln_get_version(void);

/*! \defgroup misc Misc. Functions
*
* \brief Miscelaneous functions.
*/

/*! \fn double ln_get_dec_location(char * s)
* \ingroup misc
* \brief Obtains Latitude, Longitude, RA or Declination from a string.
*/
double LIBNOVA_EXPORT ln_get_dec_location(const char *s);


/*! \fn char * ln_get_humanr_location(double location)
*  \ingroup misc
*  \brief Obtains a human readable location in the form: ddºmm'ss.ss"
*/
const char LIBNOVA_EXPORT *ln_get_humanr_location(double location);

/*!
* \ingroup misc
* \brief Calculate the distance between rectangular points
* \param a First rectangular coordinate
* \param b Second rectangular coordinate
* \return Distance between a and b.
*
* Calculate the distance between rectangular points a and b.
*/
double LIBNOVA_EXPORT ln_get_rect_distance(const struct ln_rect_posn *a,
	const struct ln_rect_posn *b);

/*! \defgroup conversion General Conversion Functions
*
* Conversion from one libnova type to another.
*/

/**
 * \fn double ln_rad_to_deg(double radians)
 * \brief radians to degrees
 * \ingroup conversion
 * \param radians Angle in radians
 * \return Angle in degrees
 */
inline double ln_rad_to_deg(double radians) { return radians * R2D; }

/**
 * convert degrees to radians
 * \ingroup conversion
 * \param degrees Angle in degrees
 * \return Angle in radians
 */
inline double ln_deg_to_rad(double degrees) { return degrees * D2R; }

/*! \fn double ln_deg_to_rad(double radians)
* \brief degrees to radians
* \ingroup conversion
*/
double LIBNOVA_EXPORT ln_deg_to_rad(double degrees);

/*!
* \brief hours to degrees
* \ingroup conversion
* \param hms struct holding hours, minutes, seconds
* \return degres
*/
double LIBNOVA_EXPORT ln_hms_to_deg(const struct ln_hms *hms);

/*! \fn void ln_deg_to_hms(double degrees, struct ln_hms *hms)
* \brief degrees to hours
* \ingroup conversion
* \param degrees degrees
* \param hms returned struct receiving hours, minutes, seconds
*/
void LIBNOVA_EXPORT ln_deg_to_hms(double degrees, struct ln_hms *hms);

/*!
* \brief hours to radians.
* \ingroup conversion
* \param hms struct holding hours, minutes, seconds
* \return radians
*/
double LIBNOVA_EXPORT ln_hms_to_rad(const struct ln_hms *hms);

/*!
* \brief radians to hours
* \ingroup conversion
* \param radians radians
* \param hms returned hms value
*/
void LIBNOVA_EXPORT ln_rad_to_hms(double radians, struct ln_hms *hms);

/*!
* \brief dms to degrees
* \ingroup conversion
* \param dms struct holding degrees, minutes, seconds
* \return degrees
*/
double LIBNOVA_EXPORT ln_dms_to_deg(const struct ln_dms *dms);

/*! \fn void ln_deg_to_dms(double degrees, struct ln_dms *dms)
* \brief degrees to dms
* \ingroup conversion
* \param degrees double degrees
* \param dms struct holding degrees, minutes, seconds
*/
void LIBNOVA_EXPORT ln_deg_to_dms(double degrees, struct ln_dms *dms);

/*!
* \brief dms to radians
* \ingroup conversion
* \param dms struct holding degrees, minutes, seconds
* \return radians
*/
double LIBNOVA_EXPORT ln_dms_to_rad(const struct ln_dms *dms);

/*! \fn void ln_rad_to_dms(double radians, struct ln_dms *dms)
* \brief radians to dms 
* \ingroup conversion
* \param radians radians
* \param dms struct to receive deegrees, minutes seconds
*/
void LIBNOVA_EXPORT ln_rad_to_dms(double radians, struct ln_dms *dms);

/*!
* \brief human readable equatorial position to double equatorial position
* \ingroup conversion
* \param hpos equatorial coordinatees (right ascension, declination)
* \param pos returned equatorial coordinatees (right ascension, declination)
*
* Accepts equatorial coordinates in hms, dms form and returns equatorial
* coordinates in double hours and degreees
*/
void LIBNOVA_EXPORT ln_hequ_to_equ(const struct lnh_equ_posn *hpos,
	struct ln_equ_posn *pos);
	
/*!
* \brief double equatorial position to human readable equatorial position
* \ingroup conversion
* \param pos equatorial coordinatees (right ascension, declination)
* \param hpos returned equatorial coordinatees (right ascension, declination)
*
* Accepts equatorial coordinates in double hours and degreees and
* returns them in hms, dms form
*/
void LIBNOVA_EXPORT ln_equ_to_hequ(const struct ln_equ_posn *pos,
	struct lnh_equ_posn *hpos);
	
/*!
* \brief human readable horizontal position to double horizontal position
* \ingroup conversion
* \param hpos azimuth and altitude in dms
* \param pos returned azimuth and altitude in degrees
*/
void LIBNOVA_EXPORT ln_hhrz_to_hrz(const struct lnh_hrz_posn *hpos,
	struct ln_hrz_posn *pos);
	
/*!
* \brief double horizontal position to human readable horizontal position
* \ingroup conversion
* \param pos azimuth and altitude in degrees
* \param hpos returned azimuth and altitude in dms
*/
void LIBNOVA_EXPORT ln_hrz_to_hhrz(const struct ln_hrz_posn *pos,
	struct lnh_hrz_posn *hpos);

/*!
 * \brief returns direction of given azimuth - like N,S,W,E,NSW,...
 * \ingroup conversion
 * \param pos azimuth and altitude in degrees
 * \return "S", "SSW", etc.
 *
 * Do not modify or free the return value
 */ 
const char LIBNOVA_EXPORT * ln_hrz_to_nswe(const struct ln_hrz_posn *pos);
	
/*!
* \brief human readable long/lat position to double long/lat position
* \ingroup conversion
* \param hpos longitude, latitude in dms
* \param pos returned longitude, latitude in degrees
*/
void LIBNOVA_EXPORT ln_hlnlat_to_lnlat(const struct lnh_lnlat_posn *hpos,
	struct ln_lnlat_posn *pos);
	
/*!
* \brief double long/lat position to human readable long/lat position
* \ingroup conversion
* \param pos longitude, latitude in deegres
* \param hpos returned longitude, latitude in dms
*/
void LIBNOVA_EXPORT ln_lnlat_to_hlnlat(const struct ln_lnlat_posn *pos,
	struct lnh_lnlat_posn *hpos);

/*!
* \brief add seconds to hms 
* \ingroup conversion 
* \param hms longitude, latitude in deegres (read/write)
* \param seconds to add to hms
*
* This function modifies hms in place
*/
void LIBNOVA_EXPORT ln_add_secs_hms(struct ln_hms *hms, double seconds);

/*!
* \brief add hms to hms 
* \ingroup conversion 
* \param source hms struct containing value to add to dest
* \param dest hms struct modified in place by adding source
*/
void LIBNOVA_EXPORT ln_add_hms(const struct ln_hms *source, struct ln_hms *dest);

/*!
* \brief puts a large angle in the correct range 0 - 360 degrees 
* \ingroup conversion 
* \param angle input angle
* \return angle restricted to [0 360)
*/
double LIBNOVA_EXPORT ln_range_degrees(double angle);

/*!
* \brief puts a large angle in the correct range 0 - 2PI radians
* \ingroup conversion
* \param angle angle in radians
* \return anglee restricted to [0 2*pi]
*/
double LIBNOVA_EXPORT ln_range_radians(double angle);

/*!
* \brief puts a large angle in the correct range 0 - 2PI radians
* \ingroup conversion
* \param angle angle in radians
* \return anglee restricted to (-2*pi 2*pi]
*/
double LIBNOVA_EXPORT ln_range_radians2(double angle);

/**
*
* \brief Convert units of AU into light days.
* \ingroup conversion
* \param dist distance in AU
* \return distance in light-days
*/
double LIBNOVA_EXPORT ln_get_light_time(double dist);

/*! \fn double ln_interpolate3 (double n, double y1, double y2, double y3)
* \brief Simple quadratic interpolation
* \param n Interpolation factor
* \param y1 Argument 1
* \param y2 Argument 2
* \param y3 Argument 3
* \return interpolation value from y1 to y3, depending on n
*
* Calculate an intermediate value of the 3 arguments for the given interpolation
* factor. n is typically -0.5 <= n <= 0.5 although this function will work
* correctly for -1 <= n <= 1. n=0 corresponds to y2
*
* Based on Meeus, (3.3)
*/
double LIBNOVA_EXPORT ln_interpolate3(double n, double y1, double y2, double y3);

/*! \fn double ln_interpolate5(double n, double y1, double y2, double y3, double y4, double y5)
* \ingroup misc
* \brief Calculate an intermediate value of the 5 arguments.
*/
double LIBNOVA_EXPORT ln_interpolate5(double n, double y1, double y2, double y3,
	double y4, double y5);

/*! \fn double ln_find_max(double (*f) (double, double *), double from, double to, double *arg)
* \brief Find local maximum of function f() at given interval by Golden Section method.
* \ingroup misc
*/
double LIBNOVA_EXPORT ln_find_max(double (*func) (double, double *),
	double from, double to, double *arg);

/*! \fn double ln_find_zero(double (*f) (double, double *), double from, double to, double *arg)
* \brief Find zero of function f() at given interval by Newton method.
* \ingroup misc
*/
double LIBNOVA_EXPORT ln_find_zero(double (*func) (double, double *),
	double from, double to, double *arg);

#ifdef __WIN32__

/* Catches calls to the POSIX gmtime_r and converts them to a related WIN32 version. */
struct tm *gmtime_r (time_t *t, struct tm *gmt);

#ifndef __MINGW__
/* Catches calls to the POSIX gettimeofday and converts them to a related WIN32 version. */
int gettimeofday(struct timeval *tp, struct timezone *tzp);
#endif // !__MINGW__

/* Catches calls to the POSIX strtok_r and converts them to a related WIN32 version. */
char *strtok_r(char *str, const char *sep, char **last);

#endif /* __WIN32__ */

/* C89 substitutions for C99 functions. */
#ifdef __C89_SUB__

/* Simple cube root */
double cbrt(double x);

#endif /* __C89_SUB__ */

#if defined(__WIN32__) || defined(sun) || defined(__C89_SUB__)

/* Not a Number function generator */
double nan(const char *code);

#endif /* defined(__WIN32__) || defined(sun) || defined(__C89_SUB__) */

#ifdef __cplusplus
};
#endif

#endif
