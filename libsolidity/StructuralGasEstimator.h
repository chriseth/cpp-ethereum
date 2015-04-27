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

#pragma once

#include <libevmasm/GasMeter.h>
#include <libevmasm/Assembly.h>

namespace dev
{
namespace solidity
{

class StructuralGasEstimator
{
public:
	/// Estimates the gas consumption for every assembly item in the given assembly and stores
	/// it by source location.
	void performEstimation(eth::AssemblyItems const& _items);
};

}
}
