//
// Copyright 2012 Josh Blum
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with io_sig program.  If not, see <http://www.gnu.org/licenses/>.

#include "element_impl.hpp"
#include <gnuradio/element.hpp>
#include <boost/detail/atomic_count.hpp>

static boost::detail::atomic_count unique_id_pool(0);

using namespace gnuradio;

Element::Element(void)
{
    //NOP
}

Element::Element(const std::string &name)
{
    this->reset(new ElementImpl());
    VAR(name);
    (*this)->name = name;
    (*this)->unique_id = ++unique_id_pool;

    //default io signature to something
    IOSignature sig; sig.push_back(1);
    this->set_input_signature(sig);
    this->set_output_signature(sig);
}

long Element::unique_id(void) const
{
    return (*this)->unique_id;
}

std::string Element::name(void) const
{
    return (*this)->name;
}


void Element::set_output_signature(const IOSignature &sig)
{
    (*this)->output_signature = sig;
}

void Element::set_input_signature(const IOSignature &sig)
{
    (*this)->input_signature = sig;
}

const IOSignature &Element::input_signature(void) const
{
    return (*this)->input_signature;
}

const IOSignature &Element::output_signature(void) const
{
    return (*this)->output_signature;
}