// Copyright (c) Microsoft
// All rights reserved
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED,
// INCLUDING WITHOUT LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
// See the Apache Version 2.0 License for specific language governing permissions and limitations under the License.
/// <tags>P1</tags>
/// <summary>Create array using 1D iterator specialized constructors - uses deque</summary>

#include <deque>
#include "./../../../constructor.h"
#include <amptest_main.h>

template<typename _type, int _D0>
bool test_feature()
{
    const int _rank = 1;

    {
        std::deque<_type> data(_D0);
        for (int i = 0; i < _D0; i++)
            data[i] = (_type)rand();

        bool pass = test_feature_itr<_type, _rank, _D0>(data.begin(), data.end()) &&
            test_feature_itr<_type, _rank, _D0>(data.rbegin(), data.rend()) &&
            test_feature_itr<_type, _rank, _D0>(data.cbegin(), data.cend()) &&
            test_feature_itr<_type, _rank, _D0>(data.crbegin(), data.crend());

        if (!pass)
            return false;
    }

    return true;
}

runall_result test_main()
{
    // Test is using doubles therefore we have to make sure that it is not executed
    // on devices that does not support double types.
	accelerator::set_default(require_device_with_double().get_device_path());

	runall_result result;

	result &= REPORT_RESULT((test_feature<int, 1>()));
	result &= REPORT_RESULT((test_feature<unsigned int, 91>()));
	result &= REPORT_RESULT((test_feature<float, 5>()));
	result &= REPORT_RESULT((test_feature<double, 31>()));

	return result;
}

