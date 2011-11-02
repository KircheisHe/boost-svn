/*=============================================================================
    Copyright (c) 2011 Daniel James

    Use, modification and distribution is subject to the Boost Software
    License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
    http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/

#if !defined(BOOST_QUICKBOOK_ID_MANAGER_HPP)
#define BOOST_QUICKBOOK_ID_MANAGER_HPP

#include <boost/scoped_ptr.hpp>
#include <string>

namespace quickbook
{
    // id_category
    //
    // Higher categories get priority over lower ones.

    struct id_category
    {
        enum categories
        {
            default_category = 0,
            numbered,           // Just used to avoid random docbook ids
            generated,          // Generated ids for other elements.
            generated_heading,  // Generated ids for headings.
            generated_section,  // Generated ids for sections.
            generated_doc,      // Generated ids for document.
            explicit_id         // Explicitly given by user
        };

        id_category() : c(default_category) {}
        id_category(categories c) : c(c) {}
        explicit id_category(int c) : c(categories(c)) {}

        bool operator==(id_category rhs) const { return c == rhs.c; }

        categories c;
    };

    struct id_state;
    struct section_manager;

    struct id_manager
    {
        id_manager();
        ~id_manager();

        struct start_file_info {
            std::string doc_id;
            std::string placeholder;
        };

        start_file_info start_file_with_docinfo(
                unsigned qbk_version,
                std::string const& include_doc_id,
                std::string const& id,
                std::string const& title);

        void start_file(
                std::string const& include_doc_id,
                std::string const& id,
                std::string const& title);

        void end_file();

        std::string begin_section(std::string const&, id_category);
        void end_section();
        int section_level() const;

        std::string old_style_id(std::string const&, id_category);
        std::string add_id(std::string const&, id_category);
        std::string add_anchor(std::string const&, id_category);

        std::string replace_placeholders(std::string const&) const;
    private:
        boost::scoped_ptr<id_state> state;
        boost::scoped_ptr<section_manager> current_section;
    };
}

#endif
