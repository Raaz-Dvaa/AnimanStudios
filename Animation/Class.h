#pragma once
#include"Header.h"
#include"Traj.h"

/*ref class Sphere1 {
public:
	Trajectory^ Tr;
	array<PointF>^ initial, ^ transformed;

	Sphere1() {
		initial = gcnew array<PointF>(1);
		initial[0] = PointF(339, 209);
		Complex_Traj^ T = gcnew Complex_Traj(2);
		T->add(gcnew Traj_Scale(PointF(339, 209), 0.01, 0.01));
		T->add(gcnew Traj_Rotate(PointF(339, 209), 0.1, atan(209 / 339)));
		Tr = T;
	}

	void add(array<PointF>^ points) {
		initial = points;
		transformed = gcnew array<PointF>(initial->Length);
	}

	void Update() {
		Tr->reset();
		Complex_Traj^ T = gcnew Complex_Traj(3);
		T->add(gcnew Traj_Scale(PointF(339, 209), 0.005, 0.005));
		T->add(gcnew Traj_Rotate(PointF(339, 209), 0.1, atan(209 / 339)));
		T->add(gcnew Traj_Move(PointF(0, 0), 0, -0.6));
		Tr = T;
	}
	void Update1() {
		Tr->reset();
		Complex_Traj^ T = gcnew Complex_Traj(1);
		T->add(gcnew Traj_Rotate(PointF(339, 209), 0.1, atan(209 / 339)));
		Tr = T;
	}
	////////////////////////////////////////////
	ref class Traj_Harmonic : public Trajectory {
public:
	Traj_Harmonic(float fo, float A, float omega, float phi) {
		this->fo = fo;
		this->A = A;
		this->omega = omega;
		this->phi = phi;
	}
protected:
	void position(float t, array<float, 2>^ M)override {
		float f = fo + A * sin(omega * t + phi);
		move_mat(t, f, M);
	}
private:
	float fo, A, omega, phi;
};


};*/

ref class Head {
public:
	Trajectory^ Tr;
	array<PointF>^ init, ^ transformed;


	Head() {
		init = gcnew array<PointF>(1);
		init[0] = PointF(165, 194);
		Complex_Traj^ T = gcnew Complex_Traj(2);
		T->add(gcnew Traj_Harmonic(0, 2, 0.5, 30));
		T->add(gcnew Traj_Rotate(PointF(143, 147), 0.1, atan(147 / 143)));
		Tr = T;
	}

	void add(array<PointF>^ points) {
		init = points;
		transformed = gcnew array<PointF>(init->Length);
	}

	void Update() {
		Tr->reset();
		Complex_Traj^ T = gcnew Complex_Traj(3);
		/*T->add(gcnew Traj_Scale(PointF(339, 209), 0.005, 0.005));
		T->add(gcnew Traj_Rotate(PointF(339, 209), 0.1, atan(209 / 339)));
		T->add(gcnew Traj_Move(PointF(0, 0), 0, -0.6));*/
		T->add(gcnew Traj_Harmonic());
		Tr = T;
	}
};

