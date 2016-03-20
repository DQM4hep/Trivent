  /// \file Unit.h
/*
 *
 * Unit.h header template automatically generated by a class generator
 * Creation date : ven. mars 18 2016
 *
 * This file is part of Trivent libraries.
 * 
 * Trivent is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * Trivent is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Trivent.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef UNIT_H
#define UNIT_H

// -- std headers
#ifdef __APPLE__
#include <_types.h>
#include <_types/_uint8_t.h>
#include <_types/_uint16_t.h>
#include <_types/_uint32_t.h>
#include <_types/_uint64_t.h>
#include <sys/_types/_int16_t.h>
#include <sys/_types/_int64_t.h>
#else
#include <stdint.h>
#endif
#include <string>
#include <set>

namespace trivent
{

class Event;

/** 
 *  @brief  Unit class
 *
 *  Base unit object class used in Trivent time clustering.
 */ 
class Unit 
{
	friend class Event;
public:
	/**
	 *  @brief  Constructor
	 *
	 *  @param  type the unit type
	 *  @param  time the timestamp of the unit
	 *  @param  pUserInput the user input to store
	 */
	Unit(const std::string &type, uint64_t time, void *pUserInput);

	/**
	 *  @brief  Get time
	 */
	uint64_t getTime() const;

	/**
	 *  @brief  Get user input
	 */
	void *getUserInput() const;

	/**
	 *  @brief  Get the collection name in which the unit is registered
	 */
	const std::string &getCollectionName() const;

	/**
	 *  @brief  Get the unit type
	 */
	const std::string &getType() const;

private:
	/**
	 *  @brief  Set the collection name in which the unit is registered
	 *
	 *  @param  collectionName the collection name in which the unit is stored
	 */
	void setCollectionName(const std::string &collectionName);

private:
	uint64_t                        m_time;                 ///< The user time stamp
	void                           *m_pUserInput;           ///< The user input pointer
	std::string                     m_collectionName;       ///< The collection name of the unit
	std::string                     m_type;                 ///< The unit type
};

typedef std::set <Unit*> UnitSet;

} 

#endif  //  UNIT_H
