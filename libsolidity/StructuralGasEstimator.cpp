/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * @author Christian <c@ethdev.com>
 * @date 2015
 * Gas consumption estimator working alongside the AST.
 */

#include "StructuralGasEstimator.h"
#include <map>
#include <libsolidity/AST.h>

using namespace std;
using namespace dev;
using namespace dev::eth;
using namespace dev::solidity;

void StructuralGasEstimator::performEstimation(AssemblyItems const& _items)
{
	set<SourceLocation> allLocations;
	map<SourceLocation, GasMeter::GasConsumption> particularCosts;
	vector<SourceLocation> rootLocations;
	map<SourceLocation, SourceLocation> parentMap;
	map<SourceLocation, GasMeter::GasConsumption> cumulativeCosts;

	GasMeter meter;

	for (auto const& item: _items)
	{
		allLocations.insert(item.getLocation());
		particularCosts[item.getLocation()] += meter.estimateMax(item);
	}
}
