// test1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;






float log2(float x)
{
	return log(x)/log(2.0);
}

float sumArray(std::vector<float> x)
{
	if(x.empty()){return 0;}

	int res=0;
	for (int i = 0; i < x.size(); i++)
	{
		res+=x[i];
	}
	return res;
}
float maxArray(std::vector<float> x)
{
	if(x.empty()){return 0;}

	int res=INT_MIN;
	for (int i = 0; i < x.size(); i++)
	{
		if(res<x[i])
		{
			res=x[i];
		}
	}
	return res;
}
int argmaxArray(std::vector<float> x)
{
	if(x.empty()){return 0;}

	int res=INT_MIN;
	int arg=0;
	for (int i = 0; i < x.size(); i++)
	{
		if(res<x[i])
		{
			res=x[i];
			arg=i;
		}
	}
	return arg;
}
std::vector<float> cumsumArray(std::vector<float> x)
{
	std::vector<float> v=std::vector<float>();

	if(x.empty()){return v;}

	float temp=0;

	for(int i=0;i<x.size();i++)
	{
		temp+=x[i];
		v.push_back(temp);
	}
	return v;
}
std::vector<float> whereArrayMore(std::vector<float> x,float more)
{
	std::vector<float> v=std::vector<float>();

	if(x.empty()){return v;}

	float temp=0;

	for(int i=0;i<x.size();i++)
	{
		if(x[i]>more)
		{
			v.push_back(x[i]);
		}
	}
	return v;
}

std::vector<float> log2Array(std::vector<float> x)
{
	std::vector<float> v=std::vector<float>();

	if(x.empty()){return v;}

	for(int i=0;i<x.size();i++)
	{
		v.push_back(log2(x[i]));
	}
	return v;
}


std::vector<float> addArray(std::vector<float> x,float div)
{
	std::vector<float> v=std::vector<float>();

	if(x.empty()){return v;}

	for(int i=0;i<x.size();i++)
	{
		v.push_back(x[i] + div);
	}
	return v;
}

std::vector<float> divisionArray(std::vector<float> x,float div)
{
	std::vector<float> v=std::vector<float>();
	
	if(x.empty()){return v;}

	for(int i=0;i<x.size();i++)
	{
		v.push_back(x[i] / div);
	}
	return v;
}
std::vector<float> substractArray(std::vector<float> x,float div)
{
	std::vector<float> v=std::vector<float>();

	if(x.empty()){return v;}

	for(int i=0;i<x.size();i++)
	{
		v.push_back(x[i] - div);
	}
	return v;
}
std::vector<float> multiplyArray(std::vector<float> x,float div)
{
	std::vector<float> v=std::vector<float>();

	if(x.empty()){return v;}

	for(int i=0;i<x.size();i++)
	{
		v.push_back(x[i] * div);
	}
	return v;
}
std::vector<float> powArray(std::vector<float> x,float div)
{
	std::vector<float> v=std::vector<float>();

	if(x.empty()){return v;}

	for(int i=0;i<x.size();i++)
	{
		v.push_back(pow(x[i],div));
	}
	return v;
}





std::vector<float> multiplyArrays(std::vector<float> x,std::vector<float> y)
{
	std::vector<float> v=std::vector<float>();
	
	if(x.empty() || y.empty()){return v;}

	for(int i=0;i<x.size();i++)
	{
		v.push_back(x[i] * y[i]);
	}
	return v;
}

std::vector<float> extractDistParams(std::vector<float> x,std::vector<float> f)
{
	float E=sumArray(x);

	std::vector<float> fn=divisionArray(f,E);

	std::vector<float> tempM1=multiplyArrays(x,fn);

	float m1=sumArray(tempM1);


	std::vector<float> temp=substractArray(x,m1);


	float m2=sumArray(multiplyArrays(powArray(temp,2),fn));
	float m3=sumArray(multiplyArrays(powArray(temp,3),fn));
	float m4=sumArray(multiplyArrays(powArray(temp,4),fn));

	float k = m4 / pow(m2, 2) - 3;

	std::vector<float> cs=cumsumArray(fn);

	float med=whereArrayMore(x,0.5)[0];

	float skew = m3 / pow(m2 , (3 / 2));

	float peak = maxArray(f);

	float peak_loc=x[argmaxArray(f)];

	std::vector<float> temp1P=whereArrayMore(x,0);
	std::vector<float> temp2P=whereArrayMore(fn,0);

	std::vector<float> p=multiplyArrays(temp1P,temp2P);

	std::vector<float> temp1Entropy=log2Array(p);
	std::vector<float> temp2Entropy=multiplyArrays(p,temp1Entropy);

	float entropy=-sumArray(temp2Entropy);

	std::vector<float> result(9);

	result[0]=E;
	result[1]=m1;
	result[2]=m2;
	result[3]=med;
	result[4]=k;
	result[5]=peak;
	result[6]=peak_loc;
	result[7]=entropy;
	result[8]=skew;

	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<float> x=std::vector<float>();
	std::vector<float> f=std::vector<float>();

	float temp=0;
	printf("Enter x1>");scanf_s("%f",&temp);x.push_back(temp);
	printf("Enter x2>");scanf_s("%f",&temp);x.push_back(temp);
	printf("Enter f1>");scanf_s("%f",&temp);f.push_back(temp);
	printf("Enter f2>");scanf_s("%f",&temp);f.push_back(temp);

	std::vector<float> res=extractDistParams(x,f);

	printf("E:%f \n",res[0]);
	printf("m1:%f \n",res[1]);
	printf("m2:%f \n",res[2]);
	printf("med:%f \n",res[3]);
	printf("k:%f \n",res[4]);
	printf("peak:%f \n",res[5]);
	printf("peak_loc:%f \n",res[6]);
	printf("entropy:%f \n",res[7]);
	printf("skew:%f \n",res[8]);

	int pause;
	std:cin >> pause;
	return 0;
}