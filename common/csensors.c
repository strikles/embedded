/**
 * @file sensors.c
 * @brief sensors
 * common mock sensors definitions
 *
 * @author Claudio Neto
 *
 * @date 3/11/2015
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cdefines.h"
#include "csensors.h"

volatile Reading_t readings[max_sensors];

/**
 * helper - gets a measurement
 */
uint16_t getSensorReadingStr(eSensor s, char buffer[])
{
  // reset buffer
  bzero(buffer, 255);

  // assert m
  switch(s)
  {
    case brightness:
    {
      // test indexes
      sprintf(buffer, "%s", brightness_str[readings[brightness].value]);
      break;
    }
    default:
    {
      sprintf(buffer, "%d", readings[s].value);
      break;
    }
  }

  printf("Reading: %s\n", buffer);

  return 0;
}

/**
 * helper - sets a random measurement value
 */
int newMeasurement(eSensor s)
{
  switch(s)
  {
    case battery:
      return (rand() % 100);
    case brightness:
      return (rand() % max_brightness_levels);
    case humidity:
      return (rand() % 100);
    case noise:
      return (rand() % 100);
    case personsPassed:
    {
      readings[personsPassed].value++;
      return readings[personsPassed].value;
    }
    case temperature:
      return (rand() % 100);
    default:
    {
      // assert
      printf("newMeasurement invalid sensor: %d\n", s);
      return -1;
    }
  }
}

/**
 * helper - loop to generate measurements
 */
uint16_t generateMeasurements(void)
{
  uint16_t ndx;
  for(ndx = 0; ndx < max_sensors; ++ndx)
  {
    readings[ndx].value = newMeasurement(ndx);
    readings[ndx].elapsed = 16;
    readings[ndx].interval = 15;
  }

  return 0;
}
