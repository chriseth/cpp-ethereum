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
 * Unit tests for the gas estimator.
 */

#include <test/libsolidity/solidityExecutionFramework.h>
#include <libsolidity/StructuralGasEstimator.h>

using namespace std;
using namespace dev::eth;
using namespace dev::solidity;

namespace dev
{
namespace solidity
{
namespace test
{

class GasMeterTestFramework: public ExecutionFramework
{
public:
	GasMeterTestFramework() { }
	void compile(string const& _sourceCode)
	{
		dev::solidity::CompilerStack compiler(false);
		compiler.addSource("", _sourceCode);
		ETH_TEST_REQUIRE_NO_THROW(compiler.compile(), "Compiling contract failed");

		StructuralGasEstimator estimator;
		AssemblyItems const* items = compiler.getRuntimeAssemblyItems("");
		SourceUnit const& sourceUnit = compiler.getAST();
		BOOST_REQUIRE(items != nullptr);
		m_gasCosts = estimator.performEstimation(*items, std::vector<SourceUnit const*>({&sourceUnit}));
	}

protected:
	map<ASTNode const*, eth::GasMeter::GasConsumption[2]> m_gasCosts;
};

BOOST_FIXTURE_TEST_SUITE(GasMeterTests, GasMeterTestFramework)

BOOST_AUTO_TEST_CASE(smoke_test)
{
	char const* sourceCode = R"(
		contract test {
			function f(uint a) returns (uint b) {
				return a;
			}
		})";
	compile(sourceCode);
}

BOOST_AUTO_TEST_SUITE_END()

}
}
}
