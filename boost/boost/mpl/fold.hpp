//-----------------------------------------------------------------------------
// boost mpl/fold.hpp header file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2001-02
// Aleksey Gurtovoy, David Abrahams
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#ifndef BOOST_MPL_FOLD_HPP_INCLUDED
#define BOOST_MPL_FOLD_HPP_INCLUDED

#include "boost/mpl/aux_/iter_fold_if.hpp"
#include "boost/mpl/aux_/fold_op.hpp"
#include "boost/mpl/aux_/fold_pred.hpp"
#include "boost/mpl/begin_end.hpp"
#include "boost/mpl/project1st.hpp"
#include "boost/mpl/lambda.hpp"
#include "boost/mpl/aux_/lambda_spec.hpp"

namespace boost {
namespace mpl {

template<
      typename Sequence
    , typename State
    , typename ForwardOp
    , typename BackwardOp = project1st<_,_>
    >
struct fold
{
 private:
    typedef typename begin<Sequence>::type first_;
    typedef typename end<Sequence>::type last_;
    typedef aux::fold_pred<last_> pred_;

    typedef aux::fold_op< typename lambda<ForwardOp>::type > forward_op_;
    typedef aux::fold_op< typename lambda<BackwardOp>::type > backward_op_;

 public:
    typedef typename aux::iter_fold_if<
          first_
        , State
        , forward_op_
        , pred_
        , backward_op_
        , pred_
        >::state type;
};

BOOST_MPL_AUX_LAMBDA_SPEC(3, fold)
BOOST_MPL_AUX_LAMBDA_SPEC(4, fold)

} // namespace mpl
} // namespace boost

#endif // BOOST_MPL_FOLD_HPP_INCLUDED
