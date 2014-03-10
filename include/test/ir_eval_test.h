/**
 * @file ir_eval_test.h
 * @author Sean Massung
 *
 * All files in META are released under the MIT license. For more details,
 * consult the file LICENSE in the root of the project.
 */

#ifndef META_IR_EVAL_TEST_H_
#define META_IR_EVAL_TEST_H_

#include "test/inverted_index_test.h"
#include "index/eval/ir_eval.h"
#include "index/ranker/okapi_bm25.h"
#include "test/unit_test.h"

namespace meta
{
namespace testing
{

int ir_eval_tests();
}
}

#endif
