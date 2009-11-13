/*
 *  Copyright 2008-2009 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <string>
#include <stdexcept>

namespace cusp
{

    class exception : public std::exception
    {
        public:
            template <typename MessageType>
            exception(const MessageType& message) : message(message) {}
            ~exception() throw() {}
            const char* what() const throw() { return message.c_str(); }

        protected:
            std::string message;
    };
    
    class not_implemented_exception : public exception
    {
        public:
            template <typename MessageType>
            not_implemented_exception(const MessageType& message) : exception(message) {}
    };

    class io_exception : public exception
    {
        public:
            template <typename MessageType>
            io_exception(const MessageType& message) : exception(message) {}
    };

    class invalid_input_exception : public exception
    {
        public:
            template <typename MessageType>
            invalid_input_exception(const MessageType& message) : exception(message) {}
    };
    
    class format_conversion_exception : public exception
    {
        public:
            template <typename MessageType>
            format_conversion_exception(const MessageType& message) : exception(message) {}
    };

} // end namespace cusp

