#ifndef LIBNOVA_ELP_H
#define LIBNOVA_ELP_H

#include "lunar-priv.h"

/* sequence sizes */
#define ELP1_SIZE	1023		/* Main problem. Longitude periodic terms (sine) */
#define ELP2_SIZE	918		/* Main problem. Latitude (sine) */
#define ELP3_SIZE	704		/* Main problem. Distance (cosine) */
#define ELP4_SIZE	347		/* Earth figure perturbations. Longitude */
#define ELP5_SIZE	316		/* Earth figure perturbations. Latitude */
#define ELP6_SIZE	237		/* Earth figure perturbations. Distance */
#define ELP7_SIZE	14		/* Earth figure perturbations. Longitude/t */
#define ELP8_SIZE	11		/* Earth figure perturbations. Latitude/t */
#define ELP9_SIZE	8		/* Earth figure perturbations. Distance/t */
#define ELP10_SIZE	14328		/* Planetary perturbations. Table 1 Longitude */
#define ELP11_SIZE	5233		/* Planetary perturbations. Table 1 Latitude */
#define ELP12_SIZE	6631		/* Planetary perturbations. Table 1 Distance */
#define ELP13_SIZE	4384		/* Planetary perturbations. Table 1 Longitude/t */
#define ELP14_SIZE	833		/* Planetary perturbations. Table 1 Latitude/t */
#define ELP15_SIZE	1715		/* Planetary perturbations. Table 1 Distance/t */
#define ELP16_SIZE	170		/* Planetary perturbations. Table 2 Longitude */
#define ELP17_SIZE	150		/* Planetary perturbations. Table 2 Latitude */
#define ELP18_SIZE	114		/* Planetary perturbations. Table 2 Distance */
#define ELP19_SIZE	226		/* Planetary perturbations. Table 2 Longitude/t */
#define ELP20_SIZE	188		/* Planetary perturbations. Table 2 Latitude/t */
#define ELP21_SIZE	169		/* Planetary perturbations. Table 2 Distance/t */
#define ELP22_SIZE	3		/* Tidal effects. Longitude */
#define ELP23_SIZE	2		/* Tidal effects. Latitude */
#define ELP24_SIZE	2		/* Tidal effects. Distance */
#define ELP25_SIZE	6		/* Tidal effects. Longitude/t */
#define ELP26_SIZE	4		/* Tidal effects. Latitude/t */
#define ELP27_SIZE	5		/* Tidal effects. Distance/t */
#define ELP28_SIZE	20		/* Moon figure perturbations. Longitude */
#define ELP29_SIZE	12		/* Moon figure perturbations. Latitude */
#define ELP30_SIZE	14		/* Moon figure perturbations. Distance */
#define ELP31_SIZE	11		/* Relativistic perturbations. Longitude */
#define ELP32_SIZE	4		/* Relativistic perturbations. Latitude */
#define ELP33_SIZE	10		/* Relativistic perturbations. Distance */
#define ELP34_SIZE	28		/* Planetary perturbations - solar eccentricity. Longitude/t2 */
#define ELP35_SIZE	13		/* Planetary perturbations - solar eccentricity. Latitude/t2 */
#define ELP36_SIZE	19		/* Planetary perturbations - solar eccentricity. Distance/t2 */

extern const struct main_problem elp1[];
extern const struct main_problem elp2[];
extern const struct main_problem elp3[];
extern const struct earth_pert elp4[];
extern const struct earth_pert elp5[];
extern const struct earth_pert elp6[];
extern const struct earth_pert elp7[];
extern const struct earth_pert elp8[];
extern const struct earth_pert elp9[];
extern const struct planet_pert elp10[];
extern const struct planet_pert elp11[];
extern const struct planet_pert elp12[];
extern const struct planet_pert elp13[];
extern const struct planet_pert elp14[];
extern const struct planet_pert elp15[];
extern const struct planet_pert elp16[];
extern const struct planet_pert elp17[];
extern const struct planet_pert elp18[];
extern const struct planet_pert elp19[];
extern const struct planet_pert elp20[];
extern const struct planet_pert elp21[];
extern const struct earth_pert elp22[];
extern const struct earth_pert elp23[];
extern const struct earth_pert elp24[];
extern const struct earth_pert elp25[];
extern const struct earth_pert elp26[];
extern const struct earth_pert elp27[];
extern const struct earth_pert elp28[];
extern const struct earth_pert elp29[];
extern const struct earth_pert elp30[];
extern const struct earth_pert elp31[];
extern const struct earth_pert elp32[];
extern const struct earth_pert elp33[];
extern const struct earth_pert elp34[];
extern const struct earth_pert elp35[];
extern const struct earth_pert elp36[];


#endif /* LIBNOVA_ELP_H */
