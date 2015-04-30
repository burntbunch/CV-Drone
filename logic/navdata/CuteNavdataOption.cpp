#include "CuteNavdataOption.h"

/*
 * CV-Drone
 * Copyright (C) 2015 www.burntbunch.org
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * */

namespace Drone
{
    namespace Navdata
        {
        /*!
         * \brief CuteNavdataOption::CuteNavdataOption Abstract base class of all Navdata options type classes
         *
         *
         * \param tag The unique tag of the derived option.
         */
        CuteNavdataOption::CuteNavdataOption(u_int16_t tag)
        {
            this->tag = tag;
        }


        CuteNavdataOption::~CuteNavdataOption()
        {

        }

        /*!
         * \brief Returns the tag of the option.
         */
        u_int16_t CuteNavdataOption::getTag()
        {
            return tag;
        }


        /*!
         * \brief Returns the tag of the option.
         * \param tag The unique tag of the derived option, represented as enum.
         * \return The unique tag of the derived option, represented as int.
         */
        u_int16_t CuteNavdataOption::decodeTag(Tag tag)
        {
            return static_cast<u_int16_t>(tag);
        }

        /*!
         * \brief Returns the tag of the option.
         * \param tag The unique tag of the derived option, represented as int.
         * \return The unique tag of the derived option, represented as enum.
         */
        CuteNavdataOption::Tag CuteNavdataOption::decodeTag(u_int16_t tag)
        {
            if(tag < 28 || tag == 65535)
                return static_cast<Tag>(tag);
            return Tag::NOT_DEFINED;
        }

        /*!
         * \brief Reads a 4-byte boolean from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \return The read value.
         */
        bool CuteNavdataOption::fetchBool(QByteArray &data)
        {
            return fetchInt32(data) != 0;
        }

        /*!
         * \brief Reads a 1-byte signed integer from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \return The read value.
         */
        int8_t CuteNavdataOption::fetchInt8(QByteArray &data)
        {
            if(data.size() < 1)
                return 0;
            int8_t value = 0;
            char c = data.at(0);
            value |= *reinterpret_cast<unsigned char*>(&c);
            data.remove(0, 1);
            return value;
        }

        /*!
         * \brief Reads a 2-byte signed integer from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read value.
         */
        int16_t CuteNavdataOption::fetchInt16(QByteArray &data, bool swapEndian)
        {
            if(data.size() < 2)
                return 0;
            int16_t value = 0;
            for(int i = 0; i < 2; i++)
            {
                value <<= 8;
                char c;
                if(swapEndian)
                    c = data.at(1 - i);
                else
                    c = data.at(i);
                value |= *reinterpret_cast<unsigned char*>(&c);
            }
            data.remove(0, 2);
            return value;
        }

        /*!
         * \brief Reads a 4-byte signed integer from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read value.
         */
        int32_t CuteNavdataOption::fetchInt32(QByteArray &data, bool swapEndian)
        {
            if(data.size() < 4)
                return 0;
            int32_t value = 0;
            for(int i = 0; i < 4; i++)
            {
                value <<= 8;
                char c;
                if(swapEndian)
                    c = data.at(3 - i);
                else
                    c = data.at(i);
                value |= *reinterpret_cast<unsigned char*>(&c);
            }
            data.remove(0, 4);
            return value;
        }

        /*!
         * \brief Reads a 1-byte unsigned integer from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \return The read value.
         */
        u_int8_t CuteNavdataOption::fetchUnsignedInt8(QByteArray &data)
        {
            return static_cast<u_int8_t>(fetchInt8(data));
        }

        /*!
         * \brief Reads a 2-byte unsigned integer from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read value.
         */
        u_int16_t CuteNavdataOption::fetchUnsignedInt16(QByteArray &data, bool swapEndian)
        {
            return static_cast<u_int16_t>(fetchInt16(data, swapEndian));
        }

        /*!
         * \brief Reads a 4-byte unsigned integer from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read value.
         */
        u_int32_t CuteNavdataOption::fetchUnsignedInt32(QByteArray &data, bool swapEndian)
        {
            return static_cast<u_int32_t>(fetchInt32(data, swapEndian));
        }

        /*!
         * \brief Reads a 4-byte signed floating point value from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read value.
         */
        float CuteNavdataOption::fetchFloat(QByteArray &data, bool swapEndian)
        {
            static_assert(sizeof(float) == 4, "Float must be 32-bit!");
            if(data.size() < 4)
                return 0.0f;
            int32_t buffer = 0;
            for(int i = 0; i < 4; i++)
            {
                buffer <<= 8;
                unsigned char c = 0;
                if(swapEndian)
                    c = data.at(3-i);
                else
                    c = data.at(i);
                buffer |= c;
            }
            data.remove(0, 4);
            float result = 0.0f;
            result = *reinterpret_cast<float*>(&buffer);
            return result;
        }

        /*!
         * \brief Reads a 8-byte signed floating point value from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read value.
         */
        double CuteNavdataOption::fetchDouble(QByteArray &data, bool swapEndian)
        {
            static_assert(sizeof(double) == 8, "Double must be 64-bit!");
            if(data.size() < 8)
                return 0.0;
            int64_t buffer = 0;
            for(int i = 0; i < 8; i++)
            {
                buffer <<= 8;
                unsigned char c = 0;
                if(swapEndian)
                    c = data.at(7-i);
                else
                    c = data.at(i);
                buffer |= c;
            }
            data.remove(0, 8);
            double result = 0.0;
            result = *reinterpret_cast<double*>(&buffer);
            return result;
        }

        /*!
         * \brief Reads a 1-byte signed integer vector, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param length The number of values to read.
         * \return The read values.
         */
        vector<int8_t> CuteNavdataOption::fetchInt8Vector(QByteArray &data, int length)
        {
            vector<int8_t> result(length);
            if(length <= 0)
                return result;
            for(int i = 0;i < length; i++)
                result[i] = fetchInt8(data);
            return result;
        }

        /*!
         * \brief Reads a 2-byte signed integer vector, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param length The number of values to read.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read values.
         */
        vector<int16_t> CuteNavdataOption::fetchInt16Vector(QByteArray &data, int length, bool swapEndian)
        {
            vector<int16_t> result(length);
            if(length <= 0)
                return result;
            for(int i = 0;i < length; i++)
                result[i] = fetchInt16(data, swapEndian);
            return result;
        }

        /*!
         * \brief Reads a 4-byte signed integer vector, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param length The number of values to read.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read values.
         */
        vector<int32_t> CuteNavdataOption::fetchInt32Vector(QByteArray &data, int length, bool swapEndian)
        {
            vector<int32_t> result(length);
            if(length <= 0)
                return result;
            for(int i = 0;i < length; i++)
                result[i] = fetchInt32(data, swapEndian);
            return result;
        }

        /*!
         * \brief Reads a 1-byte unsigned integer vector, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param length The number of values to read.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read values.
         */
        vector<u_int8_t> CuteNavdataOption::fetchUnsignedInt8Vector(QByteArray &data, int length)
        {
            vector<u_int8_t> result(length);
            if(length <= 0)
                return result;
            for(int i = 0;i < length; i++)
                result[i] = fetchUnsignedInt8(data);
            return result;
        }

        /*!
         * \brief Reads a 2-byte usigned integer vector, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param length The number of values to read.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read values.
         */
        vector<u_int16_t> CuteNavdataOption::fetchUnsignedInt16Vector(QByteArray &data, int length, bool swapEndian)
        {
            vector<u_int16_t> result(length);
            if(length <= 0)
                return result;
            for(int i = 0;i < length; i++)
                result[i] = fetchUnsignedInt16(data, swapEndian);
            return result;
        }

        /*!
         * \brief Reads a 4-byte unsigned integer vector, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param length The number of values to read.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read values.
         */
        vector<u_int32_t> CuteNavdataOption::fetchUnsignedInt32Vector(QByteArray &data, int length, bool swapEndian)
        {
            vector<u_int32_t> result(length);
            if(length <= 0)
                return result;
            for(int i = 0;i < length; i++)
                result[i] = fetchUnsignedInt32(data, swapEndian);
            return result;
        }

        /*!
         * \brief Reads a 4-byte floating point vector, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param length The number of values to read.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read values.
         */
        vector<float> CuteNavdataOption::fetchFloatVector(QByteArray &data, int length, bool swapEndian)
        {
            vector<float> result(length);
            if(length <= 0)
                return result;
            for(int i = 0;i < length; i++)
                result[i] = fetchFloat(data, swapEndian);
            return result;
        }

        /*!
         * \brief Reads a 4-byte floating point matrix, with the given number of values, from the byte array and remove it.
         * \param data The reference to the given byte array.
         * \param rows The number of rows to read.
         * \param columns The number of columns to read.
         * \param swapEndian If this boolean is set to true, the method reads in inverted order.
         * \return The read values.
         */
        vector<vector<float>> CuteNavdataOption::fetchFloatMatrix(QByteArray &data, int rows, int columns, bool swapEndian)
        {
            vector<vector<float>> result(rows, vector<float>(columns));
            if(rows <= 0 || columns <= 0)
                return result;
            for(int i = 0; i < rows; i++)
                for(int j = 0; j < columns; j++)
                    result[i][j] = fetchFloat(data, swapEndian);
            return result;
        }

    }
}

