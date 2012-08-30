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

#ifndef INCLUDED_LIBGNURADIO_COMMON_IMPL_HPP
#define INCLUDED_LIBGNURADIO_COMMON_IMPL_HPP

#include <tsbe/buffer.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/dynamic_bitset.hpp>
#include <vector>
#include <iostream>

#define HERE() std::cerr << __FILE__ << ":" << __LINE__ << std::endl << std::flush;
#define VAR(x) std::cerr << #x << " = " << (x) << std::endl << std::flush;
#define ASSERT(x) if(not (x)){HERE(); std::cerr << "assert failed: " << #x << std::endl << std::flush;}

static inline unsigned long myulround(const double x)
{
    return (unsigned long)(x + 0.5);
}

static inline unsigned long long myullround(const double x)
{
    return (unsigned long long)(x + 0.5);
}

namespace gnuradio
{

typedef boost::dynamic_bitset<> BitSet;

struct Token : boost::shared_ptr<int>
{
    static Token make(void)
    {
        Token tok;
        tok.reset(new int(0));
        return tok;
    }
};

struct TopBlockMessage
{
    enum
    {
        ACTIVE,
        INERT,
        HINT,
    } what;
    size_t hint;
    Token token;
};

struct CheckTokensMessage
{
    //empty
};

struct BufferReturnMessage
{
    size_t index;
    tsbe::Buffer buffer;
};

} //namespace gnuradio

#endif /*INCLUDED_LIBGNURADIO_COMMON_IMPL_HPP*/
