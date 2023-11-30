/**
 * Author: Khoa Tran
 * Date: 20xx/xx/xx
 *
 * A simple hello world program in C
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  printf("Hello World! My name is Khoa\n");

  return 0;
}

double getAirDistance(const Airport* origin, const Airport* destination) {
    if (origin == NULL || destination == NULL) {
        return 1;
    }

    double latitudeA = origin->latitude;
    double longitudeA = origin->longitude;
    double latitudeB = destination->latitude;
    double longitudeB = destination->longitude;

    double radianLatitudeA = (latitudeA / 180.0) * M_PI;
    double radianLongitudeA = (longitudeA / 180.0) * M_PI;
    double radianLatitudeB = (latitudeB / 180.0) * M_PI;
    double radianLongitudeB = (longitudeB / 180.0) * M_PI;
    double differenceLongitude = radianLongitudeB - radianLongitudeA;
    double airDistance = acos(sin(radianLatitudeA) * sin(radianLatitudeB) + cos(radianLatitudeA) * cos(radianLatitudeB) * cos(differenceLongitude)) * radiusEarth;
    return airDistance;
}
