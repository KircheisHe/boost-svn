
// Copyright (c) Aleksey Gurtovoy 2000-2004
//
// Use, modification and distribution are subject to the Boost Software 
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy 
// at http://www.boost.org/LICENSE_1_0.txt)
//

// Preprocessed version of "boost/mpl/aux_/config/use_preprocessed.hpp" header
// -- DO NOT modify by hand!

namespace boost {
namespace mpl {

namespace aux {

template< nttp_int arity_, bool Protect > struct lambda_impl
{
    template< typename T, typename Tag > struct result_
    {
        typedef T type;
    };
};

template<> struct lambda_impl< 1,false >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef bind1<
              f_
            , arg1
            > type;
    };
};

template<> struct lambda_impl< 1,true >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef mpl::protect< bind1<
              f_
            , arg1
            > > type;
    };
};

template<> struct lambda_impl< 2,false >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        

        typedef bind2<
              f_
            , arg1, arg2
            > type;
    };
};

template<> struct lambda_impl< 2,true >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        

        typedef mpl::protect< bind2<
              f_
            , arg1, arg2
            > > type;
    };
};

template<> struct lambda_impl< 3,false >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        typedef typename lambda< typename F::arg3, Tag, false >::type arg3;
        

        typedef bind3<
              f_
            , arg1, arg2, arg3
            > type;
    };
};

template<> struct lambda_impl< 3,true >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        typedef typename lambda< typename F::arg3, Tag, false >::type arg3;
        

        typedef mpl::protect< bind3<
              f_
            , arg1, arg2, arg3
            > > type;
    };
};

template<> struct lambda_impl< 4,false >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        typedef typename lambda< typename F::arg3, Tag, false >::type arg3;
        typedef typename lambda< typename F::arg4, Tag, false >::type arg4;
        

        typedef bind4<
              f_
            , arg1, arg2, arg3, arg4
            > type;
    };
};

template<> struct lambda_impl< 4,true >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        typedef typename lambda< typename F::arg3, Tag, false >::type arg3;
        typedef typename lambda< typename F::arg4, Tag, false >::type arg4;
        

        typedef mpl::protect< bind4<
              f_
            , arg1, arg2, arg3, arg4
            > > type;
    };
};

template<> struct lambda_impl< 5,false >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        typedef typename lambda< typename F::arg3, Tag, false >::type arg3;
        typedef typename lambda< typename F::arg4, Tag, false >::type arg4;
        typedef typename lambda< typename F::arg5, Tag, false >::type arg5;
        

        typedef bind5<
              f_
            , arg1, arg2, arg3, arg4, arg5
            > type;
    };
};

template<> struct lambda_impl< 5,true >
{
    template< typename F, typename Tag > struct result_
    {
        typedef typename F::rebind f_;
        typedef typename lambda< typename F::arg1, Tag, false >::type arg1;
        typedef typename lambda< typename F::arg2, Tag, false >::type arg2;
        typedef typename lambda< typename F::arg3, Tag, false >::type arg3;
        typedef typename lambda< typename F::arg4, Tag, false >::type arg4;
        typedef typename lambda< typename F::arg5, Tag, false >::type arg5;
        

        typedef mpl::protect< bind5<
              f_
            , arg1, arg2, arg3, arg4, arg5
            > > type;
    };
};

} // namespace aux

template<
      typename T
    , typename Tag = void_
    , bool Protect = true
    >
struct lambda
{
    typedef typename aux::lambda_impl<
          ::boost::mpl::aux::template_arity<T>::value

        , bool_<Protect>::value

    >::template result_< T,Tag >::type type;
};

} // namespace mpl
} // namespace boost

