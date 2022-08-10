\page Astronomy Overview of astronomical concepts

\tableofcontents

# Reference #

General astronomical functions, from Astronomical Formulae for Calculators,
by by Jean Meeus, 4th edition, and Astronomical Algorithms, 2nd
edition.

# Coordinate Systems #

There are several different coordinate systems used in astronomy, all
different and all relatively unstable, because of precession, perturbation
and so on.

These are: Ecliptic Coordinates, Celestial Coordinates, Geographic Coordinates,
Rectangular Coordinates, and Galactic Coordinates.

See [Transformation of Coordinates](@ref transform) for a detailed discussion.


# Common terminology #

* **Meridian**: line in the sky, directly over the observer's head,
running north & south.

* **Zenith**: point directly overhead.

* **Nadir**: point directly down

* **RA/Right Ascension**: "longitude" of a body in Celestial Coordinates.
See @ref transform.

* **Declination**: "latitude" of a body in Celestial Coordinates.
See @ref transform.

* **Altitude**: angle above the horizon. See @ref transform.

* **Azimuth**: angle along the horizon, measured clockwise from south.
(sometimes north, depending on author.)  0° = South, 90° = West,
etc.. See @ref transform.

* **Celestial Coordinates**: see @ref transform
* **Ecliptic Coordinates**: see @ref transform
* **Geographic Coordinates**: see @ref transform
* **Rectangular Coordinates**: see @ref transform
* **Horizontal Coordinates**: see @ref transform

* **Hour Angle**: an object's angle west of the meridian, measured in h:m:s.
(= difference between object's RA and current sidereal time.)
Hour Angle increases to the west.
Hour Angle is measured in degrees for celestial navigation.

* **SHA**:  Sidereal Hour Angle.  Object's angle west of Aries.

* **GHA**:  Grenwich Hour Angle.  An object's angle west of Grenwich, England.

* **LHA**:  Local Hour Angle.  An object's angle west of the local meridian.

* **Nutation**: slight wobble in Earth's axis caused by the Moon. This
has an 18.6 year period. See [Nutation](@ref nutation)

* **Mean equinox**: is the intersection of the ecliptic of the date with
the mean equator of the date

* **True equinox**: is the intersection of the ecliptic of the date with
the true (instantaneous) equator of the date. That is, the
mean equinox corrected for nutation.

* **Elongation**: The angular distance from the Sun to a body. See
[Cosmos](https://astronomy.swin.edu.au/cosmos/e/elongation)

* **Place of a star**: The star's location on the celestial sphere
as seen from the center of the solar system, and referred to the
mean equator, ecliptic, and equinox of the date.

* **Apparent place of a star**: the star's location on the celestial sphere
as seen from the Earth, and referred to the
instantaneous equator, ecliptic, and equinox

* **Aberration**: Change in the apparent position of a star caused
by the relative motion of the observer (typically on Earth). See
Wikipedia: [Aberration](https://en.wikipedia.org/wiki/Aberration_(astronomy\))

* **Ephemeris time**: Time defined by the motions of the planets. This
is a more precise and more consistent time than time measured by the
rotation of the Earth, as the Earth's rate of rotation is actually
somewhat variable, and is slowing down over the years. Ephemeris
time was abandoned in 1983 in favor of dynamical time.

* **Dynamical time**: The time defined by atomic clocks. This
replaces ephemeris time.

* **Barycentric dynamical time**: the dynamical time at the barycenter of the
solar system.

* **Terrestrial dynamical time**: the dynamical time at the Earth.
This can vary from barycentric dynamical time by as much as 0.0017
second due to relatavistic effects of the Earth's orbit.

* **Anomoly**: The angle of an orbiting object around its primary,
relative to perihelion.

* **Mean Anomoly**: The anomoly assuming a circular orbit (i.e.
taking the mean rate at which the object orbits). For example, 
if the "zero" of the Earth's orbit is its perihelion, and today is two
months after perihelion, then the anomoly of the Earth's orbit is
somewhere around 60°.
In short, it's the time passed multiplied by the rate of revolution.
See [Wikipedia article](https://en.wikipedia.org/wiki/Mean_anomaly)

* **True Anomoly**: The actual angle of a body around its primary. This
is the mean anomoly corrected for an elliptical orbit.
See [Wikipedia article](https://en.wikipedia.org/wiki/True_anomaly).
Also known as **Eccentric Anomoly**.

* **Barycenter**: The intertial center of a system, aka the center of gravity.
The barycenter is the common point about which all the bodies in a system
orbit. Usually refers to the barycenter of the solar system which is near
the Sun. The barycenter of the Earth-Moon system is about 3000 miles (4800
km) from the Earth's center, so actually within the Earth itself.
See Nasa.gov [What is a Barycenter?](https://spaceplace.nasa.gov/barycenter/en/).

* **Ascending Node**:  The point in a planet's orbit where it crosses the
plane of Earth's orbit (the ecliptic) from south to north. For something
orbiting the Earth, the Earth's equator is used instead of the ecliptic.

* **Descending Node**:  The point where a planet passes the ecliptic
from north to south.

# Symbols used in Meeus #

(Note: utf-8 characters used here)

* A  Azimuth
* H  hour angle
* T  time in julian centuries from JD2000.0
* α  right ascension (alpha)
* δ  declination (delta)
* ε  obliquity of the ecliptic (epsilon)
* ε₀ mean obliquity (ignoring nutation)
* θ  sidereal time (theta)
* φ  geographic latitude (phi)
* 𝜑  geographic latitude (phi)
* λ  celestial longitude (lambda)
* β  celestial latitude (beta)

# Time #

Time can be rather difficult to deal with, as the calendar has been
changed several times over the centuries.  The current system is the
Gregorian calendar. The functions in this module convert civil
calendars into Julian dates.  All work in the library is done in
Julian time.

Julian time is simply days since noon, 1 Jan 4712 BC.  In the Julian
system, the new day starts at noon (GMT) instead of midnight.

Sometimes, time is expressed in 36525-day centuries, often centuries
since Jan 1, 1900.  The formula for this is

		jd - 2415020
		------------
		    36525

Many measurements are made relative to the vernal equinox, AKA The
First Point of Aries, which
is the point where the ecliptic intersects the equator.  This
point drifts constantly east due to
precession.  A full circle takes approximately 26,000 years.
The North pole is currently moving towards Polaris, and should
be within 28 minutes about the year 2102.  Vega should become the
pole star around the year 14000.

Furthermore, there is a small elliptical oscillation in the Earth's
axis caused by the Moon, called "nutation", which is 18.6 years in
period and 9.2 seconds in amplitude.  This causes the vernal equinox
to wobble back and forth.  Some measurements are relative to the
exact vernal equinox, and some are relative to the average vernal
equinox ignoring nutation.
See [Nutation](@ref nutation) for functions that operate on nutation.

Often, to keep things simple, a "standard" equinox, typically from
1950 or 2000, is used as the base point.


## Year: ##
These are the various years used in astronomy.

* **Tropical year**: time for the earth to revolve from vernal equinox
to vernal equinox.  Approx 365.24219 days, as of 1970.  This
is constantly changing by very small amounts.

* **Julian year**: 365.25 days.  Requires the addition of one leap day
every four years.

* **Gregorian year**: 365.2425 days.  Requires the addition of one leap
day every four years except century years, except every fourth
century.  Thus, 1900 was not a leap year, but 2000 will be.
(Historical note:  John Hamilton Moore forgot this rule in
his book "The Practical Navigator" and called 1800 a leap
year.  This mistake caused the loss of at least one ship.
Call it a Y1800 problem.)

## Month ##
The Moon revolves around the Earth every 27 days, 7 hours and 43 minutes.
This is a "sidereal month".

A solar month is the time from new moon to new moon.  Approximately
29.53 days.

## Day ##
The Earth rotates around its axis in approximately 23:56:04.
(In this time, a
star which was overhead will return to it's exact previous
location.) However in this time, it also revolves around the Sun
nearly one degree.  It takes another 3:56 minutes (average) to
"catch up" with the Sun, for a total of (average) 24 hours.

The definition of a day can be somewhat elusive.  The Earth does
not rotate at a constant rate -- it is slowing down, and with
unpredictable irregularities.  Further, because the Earth's orbit
is elliptical, the length of the day actually varies nearly a
minute throughout the year.

Because the Earth's orbit around the Sun is elliptical, the Earth
does not move around the Sun at a constant speed.  It speeds up as
it gets near to the Sun, and slows down as it gets further away.
As the Earth speeds up, the apparent length of the day increases,
and as it slows down, the apparent length of the day decreases.
The 24 hour day is only an average over the year.

* **Sidereal Day**:  Time for the earth to rotate one full rotation
relative to the vernal equinox.  23:56:04.099

* **Sidereal Time**: hours since the vernal equinox passed overhead.
(= right ascension of meridean = hour angle of vernal equinox)

* **Mean Sidereal Time**: sidereal time based on mean equinox (corrected
for nutation)

* **True Sidereal Time**: sidereal time based on exact equinox.

* **Solar Time**: hours since the Sun passed overhead, +12
(= hour angle of Sun + 12)

* **Apparent Solar Time**: solar time based on actual position of Sun.

* **Mean Solar Time**: solar time based on imaginary average Sun.

The total difference between apparent solar time and mean solar time
can be from zero to sixteen minutes.  The difference is computed
with the "equation of time"




\anchor Orbits
# Orbits #

Planets orbit around the sun; moons orbit around their planets.

Orbits are not perfect circles (although Venus comes pretty close.)
Instead, they are ellipses, with the primary at one focus.  The
point in the orbit closest to the primary is perihelion and the
furthest point is aphelion.  Not all orbits lie in the same plane;
all planets have some amount of inclination relative to the
ecliptic plane (Earth's orbital plane.)  There is no relationship
between the angle of the orbit's major axis and the orbit's
inclination.

If orbits were perfectly circular, orbits were not tilted relative
to the ecliptic, perturbations caused by other planets did not
exist, and the equinoxes did not precess, then the position of a
planet relative to the Sun could be described as a point on a
circle:

* latitude = 0
* longitude = T\*L1 + L0

(where T = time, L1 = angular rate, L0 = base angle)

In reality, the equation for the lat/lon of a planet is very
complex, and varies from planet to planet.  The basic elements are:

* Epoch	Base time.  Aka t0.
* a — semimajor axis: 1/2 length of major axis of planet's orbit.
This is a constant for each planet.
* e — eccentricity: amount orbit varies from circular.  0 = perfect circle, 1=parabola.
* i — inclination of orbit relative to ecliptic
* omega — longitude of orbit's ascending node.  Aka W0.
* N0 — mean motion.  Average speed of orbit, typically given
as degrees/day, orbits/day, orbits/year, years/orbit, etc.
* M — Mean anomoly.  Angular distance from perihelion, as if
the planet had a circular orbit.  0 = perihelion, 180 =
aphelion.
* w — argument of perihelion.  The angle from the ascending
node to the perihelion.

* pi	longitude of perihelion = omega + w
* L	mean longitude of planet relative to Sun, as if the
planet had a circular orbit.

**Notes:**

"Ascending node" refers to the point where the planet crosses
the ecliptic from south to north.

**Inclination** and **longitude of ascending node** define the plane of
the orbit.

**a,e,w** define the shape of the orbit within that plane.  **a** defines
the size, **e** defines the shape, **w** sets the angle of the major axis.

When describing satellite orbits, longitude of ascending node is
replaced by Right Ascension of Ascending Node ("RAAN")

Wikipedia article: https://en.wikipedia.org/wiki/Orbital_elements

Excellent tutorial: https://www.amsat.org/keplerian-elements-tutorial/

YouTube video: https://www.youtube.com/watch?v=yn_Nto4Bd48


