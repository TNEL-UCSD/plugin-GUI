
/*    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2012 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "Parameter.h"


Parameter::Parameter(const String& name_, bool defaultVal) 
		: name(name_), description("")
{

	defaultValue = defaultVal;

	possibleValues.add(true);
	possibleValues.add(false);

	isBool = true;
	isCont = false;
	isDisc = false;

}

Parameter::Parameter(const String& name_, float low, float high, float defaultVal)
	 : name(name_), description("")
{
	defaultValue = defaultVal;

	possibleValues.add(low);
	possibleValues.add(high);

	isCont = true;
	isBool = false;
	isDisc = false;

}

Parameter::Parameter(const String& name_, Array<var> a, int defaultVal)
	 : name(name_), description("")
{
	possibleValues = a;
	defaultValue = defaultVal; //possibleValues[defaultVal];

	isCont = false;
	isDisc = true;
	isBool = false;

}


void Parameter::setValue(float val, int chan)
{
	if (isBoolean())
	{
		if (val > 0.0f)
			values.set(chan, true);
		else
			values.set(chan, false);
	} 
	else if (isContinuous()) {

		if (val < (float) possibleValues[0])
		{
			values.set(chan, possibleValues[0]);
		} else if (val > (float) possibleValues[1]) {
			values.set(chan, possibleValues[1]);
		} else {
			values.set(chan, val);
		}

	} else {
		int index = (int) val;

		if (index >= 0 && index < possibleValues.size())
		{
			values.set(chan, possibleValues[index]);
		}

	}

}

// void BooleanParameter::setValue(float val, int chan)
// {

// 	var b = true;
// 	bool c = b;

// 	if (val > 0)
// 		values.set(chan, true);
// 	else
// 		values.set(chan, false);

// }

// void ContinuousParameter::setValue(float val, int chan)
// {
// 	if (val < low)
// 	{
// 		values.set(chan, low);
// 	} else if (val > high) {
// 		values.set(chan, high);
// 	} else {
// 		values.set(chan, val);
// 	}
// }

// void DiscreteParameter::setValue(float val, int chan)
// {
// 	int index = (int) val;

// 	if (index >= 0 && index < possibleValues.size())
// 	{
// 		values.set(chan, possibleValues[index]);
// 	}

// }

// Array<var> BooleanParameter::getPossibleValues()
// {
// 	Array<var> a;
// 	a.add(true);
// 	a.add(false);

// 	return a;

// }

// Array<var> ContinuousParameter::getPossibleValues()
// {
// 	Array<var> a;
// 	a.add(low);
// 	a.add(high);

// 	return a;
// }

// Array<var> DiscreteParameter::getPossibleValues()
// {
// 	return possibleValues;

// }


// void* BooleanParameter::operator[](int chan)
// {
// 	return (void*) values[chan];
// }

// void* ContinuousParameter::operator[](int chan)
// {
// 	return (void*) values[chan];
// }


// void* DiscreteParameter::operator[](int chan)
// {
// 	return (void*) values[chan];
// }

// BooleanParameter::BooleanParameter(const String name_, bool defaultVal) : Parameter(name_)
// {
// 	defaultValue = defaultVal;
// }

// ContinuousParameter::ContinuousParameter(const String name_,
// 										 float low_, float high_, float defaultVal)
// 										 : Parameter(name_)
// {
// 	low = low_;
// 	high = high_;

// 	defaultValue = defaultVal;

// }

// DiscreteParameter::DiscreteParameter(const String name_,
// 									 Array<var> a, int defaultVal)
// 										 : Parameter(name_)
// {
// 	possibleValues = a;

// 	defaultValue = possibleValues[defaultVal];
// }

