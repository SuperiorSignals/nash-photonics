#pragma once
#ifndef _FDTD_H_
#define _FDTD_H_

void fdtdFiveFourEight(); // One dimensional FDTD, incomplete
void fdtdSixTwoTwo(); // One dimensional FDTD, DBC (Dirichlet boundary conditions)
void fdtdSixTwoThree(); // One dimensional FDTD, PBC (Periodic boundary conditions)
void fdtdSixFiveNine(double frequency); // One dimensional FDTD, Perfect boundary conditions
void oneDimensionalFdtd();

double gridResolution(double frequency, double refractiveIndex, int wavePoints, double featureSize, int featurePoints);
double gridResolution(double frequency, double refractiveIndex, int wavePoints);
double source(double iteration, double frequency);
double timeResolution(double gridSize);
double wavelength(double frequency, double refractiveIndex);

#endif _FDTD_H
