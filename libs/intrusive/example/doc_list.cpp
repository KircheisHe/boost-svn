/////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gazta�aga  2006-2007
//
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/intrusive for documentation.
//
/////////////////////////////////////////////////////////////////////////////
//[doc_list_code
#include <boost/intrusive/list.hpp>
#include <vector>

using namespace boost::intrusive;

class MyClass  :  public list_base_hook<>   //This is a derivation hook
{
   int int_;

   public:
   //This is a member hook
   list_member_hook<> member_hook_;

   MyClass(int i)
      :  int_(i)
   {}

   int get() const
   {  return int_;  }
};

//Define a list that will store MyClass using the public base hook
typedef list< list_base_hook<>::value_traits<MyClass> >   BaseList;

//Define a list that will store MyClass using the public member hook
typedef list< list_member_hook<>::value_traits<MyClass, &MyClass::member_hook_> >   MemberList;

int main()
{
   typedef std::vector<MyClass> Vect;
   typedef Vect::iterator VectIt;
   typedef Vect::reverse_iterator VectRit;

   //Create several MyClass objects, each one
   //with a different internal number
   Vect myclassvector;
   for(int i = 0; i < 100; ++i)
      myclassvector.push_back(MyClass(i));

   BaseList baselist;
   MemberList memberlist;

   //Now insert them in the reverse order
   //in the base hook intrusive list
   for(VectIt it(myclassvector.begin()), itend(myclassvector.end())
      ; it != itend
      ; ++it){
      baselist.push_front(*it);
   }

   //Now insert them in the same order as in vector in the
   //member hook intrusive list
   for(VectIt it(myclassvector.begin()), itend(myclassvector.end())
      ; it != itend
      ; ++it){
      memberlist.push_back(*it);
   }

   //Now test lists
   {
      BaseList::reverse_iterator rbit(baselist.rbegin()), rbitend(baselist.rend());
      MemberList::iterator mit(memberlist.begin()), mitend(memberlist.end());
      VectIt  it(myclassvector.begin()), itend(myclassvector.end());

      //Test the objects inserted in the base hook list
      for(; it != itend; ++it, ++rbit){
         if(&*rbit != &*it)   return 1;
      }

      //Test the objects inserted in the member hook list
      for(it = myclassvector.begin(); it != itend; ++it, ++mit){
         if(&*mit != &*it)    return 1;
      }
   }

   return 0;
}
//]
