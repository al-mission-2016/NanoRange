// Range v3 library
//
//  Copyright Eric Niebler 2014
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// Project home: https://github.com/ericniebler/range-v3
//
//  Copyright 2005 - 2007 Adobe Systems Incorporated
//  Distributed under the MIT License(see accompanying file LICENSE_1_0_0.txt
//  or a copy at http://stlab.adobe.com/licenses.html)

//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <nanorange/algorithm/rotate_copy.hpp>
#include <utility>
#include "../catch.hpp"
#include "../test_iterators.hpp"
#include "../test_utils.hpp"

namespace stl2 = nano;

namespace {

template <class InIter, class OutIter, typename Sent = InIter>
void test_iter()
{
	int ia[] = {0, 1, 2, 3};
	const unsigned sa = sizeof(ia) / sizeof(ia[0]);
	int ib[sa] = {0};

	auto r = stl2::rotate_copy(InIter(ia), InIter(ia),
													 Sent(ia), OutIter(ib));
	CHECK(base(r.in) == ia);
	CHECK(base(r.out) == ib);

	r = stl2::rotate_copy(InIter(ia), InIter(ia), Sent(ia + 1), OutIter(ib));
	CHECK(base(r.in) == ia + 1);
	CHECK(base(r.out) == ib + 1);
	CHECK(ib[0] == 0);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 1), Sent(ia + 1),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 1);
	CHECK(base(r.out) == ib + 1);
	CHECK(ib[0] == 0);

	r = stl2::rotate_copy(InIter(ia), InIter(ia), Sent(ia + 2), OutIter(ib));
	CHECK(base(r.in) == ia + 2);
	CHECK(base(r.out) == ib + 2);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 1), Sent(ia + 2),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 2);
	CHECK(base(r.out) == ib + 2);
	CHECK(ib[0] == 1);
	CHECK(ib[1] == 0);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 2), Sent(ia + 2),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 2);
	CHECK(base(r.out) == ib + 2);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);

	r = stl2::rotate_copy(InIter(ia), InIter(ia), Sent(ia + 3), OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 1), Sent(ia + 3),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 1);
	CHECK(ib[1] == 2);
	CHECK(ib[2] == 0);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 2), Sent(ia + 3),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 2);
	CHECK(ib[1] == 0);
	CHECK(ib[2] == 1);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 3), Sent(ia + 3),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);

	r = stl2::rotate_copy(InIter(ia), InIter(ia), Sent(ia + 4), OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);
	CHECK(ib[3] == 3);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 1), Sent(ia + 4),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 1);
	CHECK(ib[1] == 2);
	CHECK(ib[2] == 3);
	CHECK(ib[3] == 0);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 2), Sent(ia + 4),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 2);
	CHECK(ib[1] == 3);
	CHECK(ib[2] == 0);
	CHECK(ib[3] == 1);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 3), Sent(ia + 4),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 3);
	CHECK(ib[1] == 0);
	CHECK(ib[2] == 1);
	CHECK(ib[3] == 2);

	r = stl2::rotate_copy(InIter(ia), InIter(ia + 4), Sent(ia + 4),
						  OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);
	CHECK(ib[3] == 3);
}

template <class InIter, class OutIter, typename Sent = InIter>
void test_rng()
{
	int ia[] = {0, 1, 2, 3};
	const unsigned sa = sizeof(ia) / sizeof(ia[0]);
	int ib[sa] = {0};

	auto r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia))),
			InIter(ia), OutIter(ib));
	CHECK(base(r.in) == ia);
	CHECK(base(r.out) == ib);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 1))),
			InIter(ia), OutIter(ib));
	CHECK(base(r.in) == ia + 1);
	CHECK(base(r.out) == ib + 1);
	CHECK(ib[0] == 0);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 1))),
			InIter(ia + 1), OutIter(ib));
	CHECK(base(r.in) == ia + 1);
	CHECK(base(r.out) == ib + 1);
	CHECK(ib[0] == 0);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 2))),
			InIter(ia), OutIter(ib));
	CHECK(base(r.in) == ia + 2);
	CHECK(base(r.out) == ib + 2);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 2))),
			InIter(ia + 1), OutIter(ib));
	CHECK(base(r.in) == ia + 2);
	CHECK(base(r.out) == ib + 2);
	CHECK(ib[0] == 1);
	CHECK(ib[1] == 0);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 2))),
			InIter(ia + 2), OutIter(ib));
	CHECK(base(r.in) == ia + 2);
	CHECK(base(r.out) == ib + 2);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 3))),
			InIter(ia), OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 3))),
			InIter(ia + 1), OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 1);
	CHECK(ib[1] == 2);
	CHECK(ib[2] == 0);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 3))),
			InIter(ia + 2), OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 2);
	CHECK(ib[1] == 0);
	CHECK(ib[2] == 1);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 3))),
			InIter(ia + 3), OutIter(ib));
	CHECK(base(r.in) == ia + 3);
	CHECK(base(r.out) == ib + 3);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 4))),
			InIter(ia), OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);
	CHECK(ib[3] == 3);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 4))),
			InIter(ia + 1), OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 1);
	CHECK(ib[1] == 2);
	CHECK(ib[2] == 3);
	CHECK(ib[3] == 0);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 4))),
			InIter(ia + 2), OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 2);
	CHECK(ib[1] == 3);
	CHECK(ib[2] == 0);
	CHECK(ib[3] == 1);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 4))),
			InIter(ia + 3), OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 3);
	CHECK(ib[1] == 0);
	CHECK(ib[2] == 1);
	CHECK(ib[3] == 2);

	r = stl2::rotate_copy(
			::as_lvalue(stl2::subrange(InIter(ia), Sent(ia + 4))),
			InIter(ia + 4), OutIter(ib));
	CHECK(base(r.in) == ia + 4);
	CHECK(base(r.out) == ib + 4);
	CHECK(ib[0] == 0);
	CHECK(ib[1] == 1);
	CHECK(ib[2] == 2);
	CHECK(ib[3] == 3);
}

template <class InIter, class OutIter, typename Sent = InIter>
void test()
{
	test_iter<InIter, OutIter, Sent>();
	test_rng<InIter, OutIter, Sent>();
}

struct S {
	int i;
};

}

TEST_CASE("alg.rotate_copy")
{
	test<forward_iterator<const int*>, output_iterator<int*> >();
	test<forward_iterator<const int*>, forward_iterator<int*> >();
	test<forward_iterator<const int*>, bidirectional_iterator<int*> >();
	test<forward_iterator<const int*>, random_access_iterator<int*> >();
	test<forward_iterator<const int*>, int*>();

	test<bidirectional_iterator<const int*>, output_iterator<int*> >();
	test<bidirectional_iterator<const int*>, forward_iterator<int*> >();
	test<bidirectional_iterator<const int*>, bidirectional_iterator<int*> >();
	test<bidirectional_iterator<const int*>, random_access_iterator<int*> >();
	test<bidirectional_iterator<const int*>, int*>();

	test<random_access_iterator<const int*>, output_iterator<int*> >();
	test<random_access_iterator<const int*>, forward_iterator<int*> >();
	test<random_access_iterator<const int*>, bidirectional_iterator<int*> >();
	test<random_access_iterator<const int*>, random_access_iterator<int*> >();
	test<random_access_iterator<const int*>, int*>();

	test<forward_iterator<const int*>, output_iterator<int*>, sentinel<const int*> >();
	test<forward_iterator<const int*>, forward_iterator<int*>, sentinel<const int*> >();
	test<forward_iterator<const int*>, bidirectional_iterator<int*>, sentinel<const int*> >();
	test<forward_iterator<const int*>, random_access_iterator<int*>, sentinel<const int*> >();
	test<forward_iterator<const int*>, int*, sentinel<const int*> >();

	test<bidirectional_iterator<const int*>, output_iterator<int*>, sentinel<const int*> >();
	test<bidirectional_iterator<const int*>, forward_iterator<int*>, sentinel<const int*> >();
	test<bidirectional_iterator<const int*>, bidirectional_iterator<int*>, sentinel<const int*> >();
	test<bidirectional_iterator<const int*>, random_access_iterator<int*>, sentinel<const int*> >();
	test<bidirectional_iterator<const int*>, int*, sentinel<const int*> >();

	test<random_access_iterator<const int*>, output_iterator<int*>, sentinel<const int*> >();
	test<random_access_iterator<const int*>, forward_iterator<int*>, sentinel<const int*> >();
	test<random_access_iterator<const int*>, bidirectional_iterator<int*>, sentinel<const int*> >();
	test<random_access_iterator<const int*>, random_access_iterator<int*>, sentinel<const int*> >();
	test<random_access_iterator<const int*>, int*, sentinel<const int*> >();

	test<const int*, output_iterator<int*> >();
	test<const int*, forward_iterator<int*> >();
	test<const int*, bidirectional_iterator<int*> >();
	test<const int*, random_access_iterator<int*> >();
	test<const int*, int*>();

	// test rvalue range
	{
		int rgi[] = {0,1,2,3,4,5};
		int rgo[6] = {0};
		auto r = stl2::rotate_copy(std::move(rgi), rgi+2, rgo);
		CHECK(r.out == stl2::end(rgo));
		CHECK(rgo[0] == 2);
		CHECK(rgo[1] == 3);
		CHECK(rgo[2] == 4);
		CHECK(rgo[3] == 5);
		CHECK(rgo[4] == 0);
		CHECK(rgo[5] == 1);
	}
}
