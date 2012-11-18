// Copyright (C) by Josh Blum. See LICENSE.txt for licensing information.

#ifndef INCLUDED_GRAS_ELEMENT_HPP
#define INCLUDED_GRAS_ELEMENT_HPP

#include <gras/gras.hpp>
#include <gras/io_signature.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

namespace gras
{

struct ElementImpl;

typedef boost::shared_ptr<ElementImpl> ElementBase;

struct GRAS_API Element : ElementBase, boost::enable_shared_from_this<Element>
{

    //! Create an empty element
    Element(void);

    //! Creates a new element given the name
    Element(const std::string &name);

    //! An integer ID that is unique across the process
    long unique_id(void) const;

    //! Get the name of this element
    std::string name(void) const;

    //! get a canonical name for this element
    std::string to_string(void) const;

    void set_output_signature(const gras::IOSignature &sig);

    void set_input_signature(const gras::IOSignature &sig);

    const gras::IOSignature &input_signature(void) const;

    const gras::IOSignature &output_signature(void) const;

    /*******************************************************************
     * Compatibility for dealing with shared ptrs of Elements
     ******************************************************************/
    /*!
     * Create an element from a shared pointer to an element.
     * Good for that factory function/shared ptr paradigm.
     */
    template <typename T>
    Element(const boost::shared_ptr<T> &elem)
    {
        *this = elem->shared_to_element();
    }

    //! Convert a shared ptr of a derived class to an Element
    Element &shared_to_element(void);

    //! for internal use only
    boost::weak_ptr<Element> weak_self;

};

} //namespace gras

#endif /*INCLUDED_GRAS_ELEMENT_HPP*/