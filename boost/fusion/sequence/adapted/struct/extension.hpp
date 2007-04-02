/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2005-2006 Dan Marsden

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_STRUCT_EXTENSION_APRIL_2_2007_1008AM)
#define FUSION_STRUCT_EXTENSION_APRIL_2_2007_1008AM

#include <boost/type_traits/add_const.hpp>

namespace boost { namespace fusion { namespace extension
{
    template <typename Struct, int N>
    struct struct_member;

    template <typename Struct>
    struct struct_size;

    template <typename Struct, int N>
    struct struct_member<Struct const, N>
    {
        typedef typename
            add_const<typename struct_member<Struct, N>::type>::type
        type;

        static type&
        call(Struct const& struct_)
        {
            return struct_member<Struct, N>::call(
                const_cast<Struct&>(struct_));
        }
    };

    template <typename Struct>
    struct struct_size<Struct const>
        : struct_size<Struct>
    {};
}}}

#endif


