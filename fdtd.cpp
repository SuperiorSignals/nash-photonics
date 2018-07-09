#include "fdtd.h"

#include <cmath>
#include <iostream>
#include <fstream>

const double C_0 = 299792458; // c0 - light speed in meters per second
const double FEATURE_SIZE = 100E-6;

// One dimensional FDTD, basic
// Incomplete, Do not use!
// lec 5.48
void fdtdFiveFourEight()
{
	const int ARRAY_SIZE = 512; // Nz
	const int STEP_COUNT = 1024; // STEPS
	int zCount = ARRAY_SIZE; // Nz
	int steps = STEP_COUNT; // STEPS
	double relativePermittivity[ARRAY_SIZE]; // ER
	double relativePermeability[ARRAY_SIZE]; // UR
	double electricField[ARRAY_SIZE]; // Ey
	double magneticField[ARRAY_SIZE]; // Hx
	double electricUpdateCoefficient[ARRAY_SIZE]; // mEy
	double magneticUpdateCoefficient[ARRAY_SIZE]; // mHx
	double lightSpeed = C_0; // c0
	double deltaTime = 1.0; // dt
	double deltaSpace = 1.0; // dz

	for (int i = 0; i < zCount; i++) { // Initialize materials to free space
		relativePermittivity[i] = 1.0;
		relativePermeability[i] = 1.0;
	}

	for (int i = 0; i < zCount; i++) { // Compute update coefficients
		electricUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermittivity[i];
		magneticUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermeability[i];
	}

	for (int i = 0; i < zCount; i++) { // Initialize fields to zero
		electricField[i] = 0.0;
		magneticField[i] = 0.0;
	}
	
	for (int i = 0; i < steps; i++) { // Main FDTD loop
		for (int j = 0; j < zCount; j++) { // Update H from E, j = nz
			magneticField[j] = magneticField[j] + magneticUpdateCoefficient[j] * (electricField[j + 1] - electricField[j]) / deltaSpace;
		}

		for (int j = 0; j < zCount; j++) { // Update E from H, j = nz
			electricField[j] = electricField[j] + electricUpdateCoefficient[j] * (magneticField[j] - magneticField[j - 1]) / deltaSpace;
		}
	}
}

// One dimensional FDTD, DBC (Dirichlet boundary conditions)
// lec 6.22
void fdtdSixTwoTwo()
{
	const int ARRAY_SIZE = 512; // Nz
	const int STEP_COUNT = 1024; // STEPS
	int zCount = ARRAY_SIZE; // Nz
	int steps = STEP_COUNT; // STEPS
	double relativePermittivity[ARRAY_SIZE]; // ER
	double relativePermeability[ARRAY_SIZE]; // UR
	double electricField[ARRAY_SIZE]; // Ey
	double magneticField[ARRAY_SIZE]; // Hx
	double electricUpdateCoefficient[ARRAY_SIZE]; // mEy
	double magneticUpdateCoefficient[ARRAY_SIZE]; // mHx
	double lightSpeed = C_0; // c0
	double deltaTime = 1.0; // dt
	double deltaSpace = 1.0; // dz

	for (int i = 0; i < zCount; i++) { // Initialize materials to free space
		relativePermittivity[i] = 1.0;
		relativePermeability[i] = 1.0;
	}

	for (int i = 0; i < zCount; i++) { // Compute update coefficients
		electricUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermittivity[i];
		magneticUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermeability[i];
	}

	for (int i = 0; i < zCount; i++) { // Initialize fields to zero
		electricField[i] = 0.0;
		magneticField[i] = 0.0;
	}

	for (int i = 0; i < steps; i++) { // Main FDTD loop
		// Do not use if-statement to implement boundary conditions
		for (int j = 0; j < zCount - 1; j++) { // Update H from E (DBC), j = nz
			magneticField[j] = magneticField[j] + magneticUpdateCoefficient[j] * (electricField[j + 1] - electricField[j]) / deltaSpace;
		}
		magneticField[zCount - 1] = magneticField[zCount - 1] + magneticUpdateCoefficient[zCount - 1] * (0 - electricField[zCount - 1]) / deltaSpace;

		electricField[0] = electricField[0] + electricUpdateCoefficient[1] * (magneticField[0] - 0) / deltaSpace;
		for (int j = 1; j < zCount; j++) { // Update E from H (DBC), j = nz
			electricField[j] = electricField[j] + electricUpdateCoefficient[j] * (magneticField[j] - magneticField[j - 1]) / deltaSpace;
		}
	}
}

// One dimensional FDTD, PBC (Periodic boundary conditions)
// lec 6.23
void fdtdSixTwoThree()
{
	const int ARRAY_SIZE = 512; // Nz
	const int STEP_COUNT = 1024; // STEPS
	int zCount = ARRAY_SIZE; // Nz
	int steps = STEP_COUNT; // STEPS
	double relativePermittivity[ARRAY_SIZE]; // ER
	double relativePermeability[ARRAY_SIZE]; // UR
	double electricField[ARRAY_SIZE]; // Ey
	double magneticField[ARRAY_SIZE]; // Hx
	double electricUpdateCoefficient[ARRAY_SIZE]; // mEy
	double magneticUpdateCoefficient[ARRAY_SIZE]; // mHx
	double lightSpeed = C_0; // c0
	double deltaTime = 1.0; // dt
	double deltaSpace = 1.0; // dz

	for (int i = 0; i < zCount; i++) { // Initialize materials to free space
		relativePermittivity[i] = 1.0;
		relativePermeability[i] = 1.0;
	}

	for (int i = 0; i < zCount; i++) { // Compute update coefficients
		electricUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermittivity[i];
		magneticUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermeability[i];
	}

	for (int i = 0; i < zCount; i++) { // Initialize fields to zero
		electricField[i] = 0.0;
		magneticField[i] = 0.0;
	}

	for (int i = 0; i < steps; i++) { // Main FDTD loop
									  // Do not use if-statement to implement boundary conditions
		for (int j = 0; j < zCount - 1; j++) { // Update H from E (DBC), j = nz
			magneticField[j] = magneticField[j] + magneticUpdateCoefficient[j] * (electricField[j + 1] - electricField[j]) / deltaSpace;
		}
		magneticField[zCount - 1] = magneticField[zCount - 1] + magneticUpdateCoefficient[zCount - 1] * (0 - electricField[zCount - 1]) / deltaSpace;

		electricField[0] = electricField[0] + electricUpdateCoefficient[1] * (magneticField[0] - 0) / deltaSpace;
		for (int j = 1; j < zCount; j++) { // Update E from H (DBC), j = nz
			electricField[j] = electricField[j] + electricUpdateCoefficient[j] * (magneticField[j] - magneticField[j - 1]) / deltaSpace;
		}
	}
}

// One dimensional FDTD, Perfect boundary conditions
// lec 6.59
void fdtdSixFiveNine(double frequency)
{
	std::ofstream outputFile;

	const int ARRAY_SIZE = 512; // Nz
	const int STEP_COUNT = 1024; // STEPS
	int zCount = ARRAY_SIZE; // Nz
	int sourceLocation = 16; // nzsrc
	int steps = STEP_COUNT; // STEPS
	double relativePermittivity[ARRAY_SIZE]; // ER
	double relativePermeability[ARRAY_SIZE]; // UR
	double electricField[ARRAY_SIZE]; // Ey
	double magneticField[ARRAY_SIZE]; // Hx
	double electricUpdateCoefficient[ARRAY_SIZE]; // mEy
	double magneticUpdateCoefficient[ARRAY_SIZE]; // mHx
	double lightSpeed = C_0; // c0
	double deltaTime = 1.0; // dt
	double deltaSpace = 1.0; // dz
	double magneticBoundary[3]; // H3, H2, H1
	double electricBoundary[3]; // E3, E2, E1
	double temporary;
	
	outputFile.open("fdtd_5_69.txt");
	if (!outputFile.is_open()) {
		std::cout << "ERROR [void fdtdSixFiveNine(double)]: ";
		std::cout << "Unable to open file " << "fdtd_4_69.txt";
		std::cout << std::endl;
		return;
	}

	deltaSpace = gridResolution(frequency, 1.0, 50);  // Compute grid resolution
	deltaTime = timeResolution(FEATURE_SIZE); // Compute time step
	temporary = deltaSpace / lightSpeed;
	deltaTime = ((deltaTime < temporary) ? deltaTime : temporary); // Courant stability condition

	outputFile << 1;
	outputFile << std::endl;
	outputFile << 0;
	outputFile << std::endl;
	outputFile << zCount;
	outputFile << std::endl;
	outputFile << steps;
	outputFile << std::endl;

	std::cout << "Grid Resolution: " << deltaSpace;
	std::cout << std::endl;
	std::cout << "Time Resolution: " << deltaTime;
	std::cout << std::endl;
	std::cout << "Source: ";
	for (int i = 0; i < zCount; i++) {
		std::cout << source(static_cast<double>(i) * deltaTime, frequency);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < zCount; i++) { // Initialize materials to free space
		relativePermittivity[i] = 1.0;
		relativePermeability[i] = 1.0;
	}

	for (int i = 0; i < zCount; i++) { // Compute update coefficients
		electricUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermittivity[i];
		magneticUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermeability[i];
	}

	for (int i = 0; i < zCount; i++) { // Initialize fields to zero
		electricField[i] = 0.0;
		magneticField[i] = 0.0;
	}

	for (int i = 0; i < 3; i++) { // Initialize boundary terms
		magneticBoundary[i] = 0;
		electricBoundary[i] = 0;
	}

	for (int i = 0; i < steps; i++) { // Main FDTD loop
									  // Do not use if-statement to implement boundary conditions
		for (int j = 0; j < zCount - 1; j++) { // Update H from E (perfect boundary conditions), j = nz
			magneticField[j] = magneticField[j] + magneticUpdateCoefficient[j] * (electricField[j + 1] - electricField[j]) / deltaSpace;
		}
		magneticField[zCount - 1] = magneticField[zCount - 1] + magneticUpdateCoefficient[zCount - 1] * (electricBoundary[2] - electricField[zCount - 1]) / deltaSpace;
		magneticBoundary[2] = magneticBoundary[1];
		magneticBoundary[1] = magneticBoundary[0];
		magneticBoundary[0] = magneticField[0];

		electricField[0] = electricField[0] + electricUpdateCoefficient[1] * (magneticField[0] - magneticBoundary[2]) / deltaSpace;
		for (int j = 1; j < zCount; j++) { // Update E from H (perfect boundary conditions), j = nz
			electricField[j] = electricField[j] + electricUpdateCoefficient[j] * (magneticField[j] - magneticField[j - 1]) / deltaSpace;
		}
		electricBoundary[2] = electricBoundary[1];
		electricBoundary[1] = electricBoundary[0];
		electricBoundary[0] = electricField[zCount - 1];

		// Inject soft source
		electricField[sourceLocation] = electricField[sourceLocation] + source(static_cast<double>(i) * deltaTime, frequency);
		for (int j = 0; j < zCount; j++) { // Write values to file
			outputFile << electricField[j];
			outputFile << std::endl;
		}
		outputFile << std::endl;
	}
	outputFile.close();
}

void oneDimensionalFdtd()
{
	const int ARRAY_SIZE = 512; // Nz (for now)
	const int STEP_SIZE = 1024;
	int zCount = ARRAY_SIZE; // Nz
	int steps = STEP_SIZE;	// STEPS
	int sourceLocation = 16; // nzsrc
	double electricField[ARRAY_SIZE];
	double magneticField[ARRAY_SIZE]; // Hx
	double relativePermittivity[ARRAY_SIZE]; // ER
	double relativePermeability[ARRAY_SIZE]; // UR
	double electricUpdateCoefficient[ARRAY_SIZE]; // mEy
	double magneticUpdateCoefficient[ARRAY_SIZE]; // mHx
	double source[STEP_SIZE]; // g
	double lightSpeed = C_0; // c0
	double deltaTime = 1.0; // dt
	double deltaSpace = 1.0; // dz

	for (int i = 0; i < zCount; i++) { // Initialize materials to free space
		relativePermeability[i] = 1;
		relativePermittivity[i] = 1;
	}

	for (int i = 0; i < zCount; i++) { // Compute update coefficients
		electricUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermittivity[i];
		magneticUpdateCoefficient[i] = lightSpeed * deltaTime / relativePermeability[i];
	}

	for (int i = 0; i < zCount; i++) { // Initialize fields to zero
		electricField[i] = 0;
		magneticField[i] = 0;
	}

	//for (int i = 0; i < steps; i++) { // Main FDTD loop
	//								  // nz (j is nz)
	//	for (int j = 0; j < zCount; j++) { // Update H from E
	//		magneticField[i] = magneticField[i] + magneticUpdateCoefficient[i] * (electricField[i + 1] - electricField[i]) / deltaSpace;
	//	}

	//	for (int j = 0; j < zCount; j++) { // Update E from H
	//		electricField[i] = electricField[i] + electricUpdateCoefficient[i] * (magneticField[i] - magneticField[i - 1]) / deltaSpace;
	//	}
	//}


	for (int i = 0; i < steps; i++) { // Main FDTD loop
									  // nz (j is nz)
		for (int j = 0; j < zCount - 1; j++) { // Update H from E (Dirichlet boundary conditions)
			magneticField[i] = magneticField[i] + magneticUpdateCoefficient[i] * (electricField[i + 1] - electricField[i]) / deltaSpace;
		}
		magneticField[zCount] = magneticField[zCount] + magneticUpdateCoefficient[zCount] * (0 - electricField[zCount]) / deltaSpace;

		electricField[0] = electricField[0] + electricUpdateCoefficient[0] * (magneticField[0] - 0) / deltaSpace;
		for (int j = 1; j < zCount; j++) { // Update E from H (Dirichlet boundary conditions)
			electricField[i] = electricField[i] + electricUpdateCoefficient[i] * (magneticField[i] - magneticField[i - 1]) / deltaSpace;
		}

		electricField[sourceLocation] = electricField[sourceLocation] + source[i];

	}
}

double gridResolution(double frequency, double refractiveIndex, int wavePoints, double featureSize, int featurePoints)
{
	double resolution; // dz1, dz
	double mechanical; // dz2

	// Limits: 10 < waveCount < 500
	if (wavePoints < 10) { // wavePoints = NRES
		wavePoints = 10;
	} else if (wavePoints > 500) {
		wavePoints = 500;
	}
	if (featurePoints < 1) { // featurePoints = NDRES
		featurePoints = 1;
	}
	resolution = wavelength(frequency, refractiveIndex) / static_cast<double>(wavePoints);
	mechanical = featureSize / featurePoints;
	resolution = ((resolution < mechanical) ? resolution : mechanical);

	return resolution; // dz
}

// Use maximum frequency and refractive index
// Increase wave points for higher resolution
double gridResolution(double frequency, double refractiveIndex, int waveCount)
{
	double resolution;

	resolution = wavelength(frequency, refractiveIndex) / static_cast<double>(waveCount);

	return resolution;
}

double source(double iteration, double frequency)
{
	double output;
	double timeConstant;
	double offset;

	timeConstant = 0.5 / frequency;
	offset = 6.0 * timeConstant;
	output = (iteration - offset) / timeConstant;
	output = output * output;
	output = exp(-output);

	return output;
}


double timeResolution(double gridSize)
{
	double deltaTime;
	double lightSpeed = C_0;

	deltaTime = gridSize / (2.0 * static_cast<double>(lightSpeed));

	return deltaTime;
}

// Calculate minimum wavelength with maximum frequency and refractive index
double wavelength(double frequency, double refractiveIndex)
{
	double wavelength; // LAMBDA
	const double lightSpeed = C_0;

	wavelength = lightSpeed / (frequency * refractiveIndex);

	return wavelength;
}