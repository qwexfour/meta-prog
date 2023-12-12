// Meta-programming library
// Copyright (C) 2023 Dmitry Ryabtsev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "meta_prog/args_switch.h"

#include <gtest/gtest.h>

using namespace meta_prog;

TEST(args_switch, basic) {
  ASSERT_EQ(switch_args_and_call([]() { return 42; }, args_switch<>{}), 42);

  // Check that the wrapper preserves reference in the return type.
  int tmp = 0;
  switch_args_and_call([](int &t) -> int & { return t; }, args_switch<>{},
                       tmp) = 23;
  ASSERT_EQ(tmp, 23);
}
