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

#ifndef _LN_TRANSFORM_H
#define _LN_TRANSFORM_H

#include <libnova/ln_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \defgroup transform Transformation of Coordinates
* \brief Transformations from one coordinate system to another.
*
* There are several different coordinate systems used in astronomy, all
* different and all relatively unstable, because of precession, perturbation
* and so on.
*
* ## Celestial Coordinates ##
*
* This is a spherical coordinate system centered at the Earth.  The
* equator of this system is the Earth's equator and the north pole
* of this system is the Earth's north pole.  Angles north and south
* are called **declination**, and are measured in degrees, +north/-south.
*
* Angles about the equator are called **right ascension**, and are
* measured in hours, minutes and seconds.  Zero hours right ascension is the
* first point in Aries,
* meaning the point where the Earth's equator crosses the ecliptic at
* the vernal equinox.  (This point was once in the constellation
* Aires, but is no longer actually in Aries due
* to precession of Earth's rotation, which causes this point to
* continuously drift east about one degree/century.)
* Right ascension increases to the east.
*
* Right ascension is measured in hours instead of degrees. This is an archaic
* convention that originated with ancient astronomers who measured an
* object's "longitudinal" position by counting the time between when
* Aries passed overhead, and when the object passed overhead.
*
* Right ascension and declination are typically referenced to
* particular epochs, such as 1950 or 2000 to
* compensate for precesion. E.g. the Yale Bright Star Catalog
* lists Rigel with these coordinatees:
*
*          1900:  05h09'43.9" -08°19'01"
*          2000:  05h14'32.3" -08°12'06"
*
* These are the positions in 1900 and 2000 respectively for Rigel. These
* values incorporate both precession and the star's proper motion.
* To obtain the RA and decl for a given date, you must account for both
* precession and proper motion for the target date relative to the epoch.
*
* As you can see, Rigel's RA changed by more than a degree over the
* last century, so don't skip this step.
*
* *Note:* most functions in libnova operate strictly with degrees, so
* given a value in hours, you must convert to degrees before calling
* functions in libnova. See @ref conversion
* for functions that can help you with this.
*
* ## Ecliptic Coordinates ##
*
* This is a spherical coordinate system either centered at the Earth
* ("geocentric") or centered at the Sun ("heliocentric").  The
* equator of this system is the plane of the Earth's orbit, with
* "north" perpindicular to Earth's orbit and
* 23.5 degrees off of the Earth's north.
*
* Angles north and south are called **latitude**, and are measured in
* degrees, +north/-south.
*
* Angles about the center are called **longitude**, and are measured in
* degrees.  Zero degrees longitude is at the first point in Aries,
* as described above.
* Ecliptic longitudes increase to the east.
*
* The name "ecliptic" comes from the fact that eclipses of the Moon
* or Sun can only happen when the moon is on the ecliptic.  By
* definition, the Sun is always on the ecliptic.
*
* ## Geographic Coordinates ##
*
* Locations on Earth are measured in latitude and longitude, in
* degrees. North latitude is positive, south is negative. Longitude
* is based at the observatory in Greenwich, England, and increases
* going west (in contrast to the IAU which switched in 1982).
*
* ## Rectangular Coordinates ##
*
* Normally, coordinates are given in terms of lattitude, longitude
* (or declination and right ascension) and distance.  Occasionally
* rectangular coordinates are used.  In such cases, the axes are:
*
* * X - towards vernal equinox = 0 degrees longitude
* * Y - 90 degrees longitude
* * Z - North
*
* ## Horizontal Coordinates ##
*
* These are coordinates of a body relative to an observer. The terms
* are azimuth (direction) and altitude (height above the horizon). In short,
* horizontal coordinates are where you point your telescope to look at
* something.
*
* Azimuth is typically given in degrees clockwise from either true north
* or true south, depending on the textbook. Libnova uses south, with
* 90° being west, 180° being north, and 270° being east.
*
* Altitude is given in degrees above the horizon. In many cases, you will
* want to adjust for the observer's height above the horizon,
* @ref refraction, and
* in the case of celestial navigation, sextant errors.
*
* ## Galactic Coordinates ##
*
* This is a spherical coordinate system centered at the center of the
* galaxy.  The equator of this system is the mean galactic equator,
* and galactic "north" is in approximately the same direction as
* terrestrial north.  This coordinate system is not used here.
*/

/*! \fn void ln_get_hrz_from_equ(struct ln_equ_posn *object, struct ln_lnlat_posn *observer, double JD, struct ln_hrz_posn *position);
* \brief Calculate horizontal coordinates from equatorial coordinates 
* \ingroup transform 
*/
/* Use get_mean_sidereal_time, get_hrz_from_equ_siderealtime */
void LIBNOVA_EXPORT ln_get_hrz_from_equ(const struct ln_equ_posn *object,
	const struct ln_lnlat_posn *observer, double JD, struct ln_hrz_posn *position);

/*!
* \brief Calculate horizontal coordinates from equatorial coordinates,
* using mean sidereal time.
* \ingroup transform 
*
* \param object Object's position in equatorial coordinates
* \param observer Observer's location on the Earth
* \param sidereal Sidereal time
* \param position Returned altitude and azimuth
*/
/* Equ 12.5,12.6 pg 88 */
void LIBNOVA_EXPORT ln_get_hrz_from_equ_sidereal_time(const struct ln_equ_posn *object,
	const struct ln_lnlat_posn *observer, double sidereal,
	struct ln_hrz_posn *position);

/*! \fn void ln_get_equ_from_ecl(struct ln_lnlat_posn *object, double JD, struct ln_equ_posn *position);
* \brief Calculate equatorial coordinates from ecliptical coordinates
* \ingroup transform
*/
/* Equ 12.3, 12.4 pg 89 */
void LIBNOVA_EXPORT ln_get_equ_from_ecl(const struct ln_lnlat_posn *object,
	double JD, struct ln_equ_posn *position);

/*! \fn void ln_get_ecl_from_equ(struct ln_equ_posn *object, double JD, struct ln_lnlat_posn *position);
* \brief Calculate ecliptical coordinates from equatorial coordinates 
* \ingroup transform
*/
/* Equ 12.1, 12.2 Pg 88 */
void LIBNOVA_EXPORT ln_get_ecl_from_equ(const struct ln_equ_posn *object, double JD,
	struct ln_lnlat_posn *position);

/*! \fn void ln_get_equ_from_hrz(struct ln_hrz_posn *object, struct ln_lnlat_posn *observer, double JD, struct ln_equ_posn *position); 
* \brief Calculate equatorial coordinates from horizontal coordinates  
* \ingroup transform
*/
/* Pg 89 */
void LIBNOVA_EXPORT ln_get_equ_from_hrz(const struct ln_hrz_posn *object,
	const struct ln_lnlat_posn *observer, double JD, struct ln_equ_posn *position);

/*! \fn void ln_get_rect_from_helio(struct ln_helio_posn *object, struct ln_rect_posn *position); 
* \brief Calculate geocentric coordinates from heliocentric coordinates  
* \ingroup transform
*/
/* Pg ?? */
void LIBNOVA_EXPORT ln_get_rect_from_helio(const struct ln_helio_posn *object,
	struct ln_rect_posn *position);

/*! \fn void ln_get_ecl_from_rect(struct ln_rect_posn *rect, struct ln_lnlat_posn *posn)
* \ingroup transform
* \brief Transform an objects rectangular coordinates into ecliptical coordinates.
*/
/* Equ 33.2
*/
void LIBNOVA_EXPORT ln_get_ecl_from_rect(const struct ln_rect_posn *rect,
	struct ln_lnlat_posn *posn);

/*! \fn void ln_get_equ_from_gal(struct ln_gal_posn *gal, struct ln_equ_posn *equ)
* \ingroup transform
* \brief Transform an object galactic coordinates into equatorial coordinates.
*/
/* Pg 94 */
void LIBNOVA_EXPORT ln_get_equ_from_gal(const struct ln_gal_posn *gal,
	struct ln_equ_posn *equ);

/*! \fn void ln_get_equ2000_from_gal(struct ln_gal_posn *gal, struct ln_equ_posn *equ)
* \ingroup transform
* \brief Transform an object galactic coordinate into J2000 equatorial coordinates.
*/
void LIBNOVA_EXPORT ln_get_equ2000_from_gal(const struct ln_gal_posn *gal,
	struct ln_equ_posn *equ);

/*! \fn void ln_get_gal_from_equ(struct ln_equ_posn *equ, struct ln_gal_posn *gal)
* \ingroup transform
* \brief Transform an object equatorial coordinates into galactic coordinates.
*/
/* Pg 94 */
void LIBNOVA_EXPORT ln_get_gal_from_equ(const struct ln_equ_posn *equ,
	struct ln_gal_posn *gal);

/*! \fn void ln_get_gal_from_equ2000(struct ln_equ_posn *equ, struct ln_gal_posn *gal)
* \ingroup transform
* \brief Transform an object J2000 equatorial coordinates into galactic coordinates.
*/
void LIBNOVA_EXPORT ln_get_gal_from_equ2000(const struct ln_equ_posn *equ,
	struct ln_gal_posn *gal);

#ifdef __cplusplus
};
#endif

#endif
