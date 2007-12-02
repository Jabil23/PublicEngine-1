/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef ATOMIC_H_
#define ATOMIC_H_

#include "../platform.h"

#ifdef PLATFORM_FREEBSD
#include <machine/atomic.h>
#endif

namespace sys {
  namespace thread {

  	class Atomic {
  		void static inline incrementInt(uint32* value) {
			#ifdef PLATFORM_UNIX
  				atomic_add_int(value, 1);
			#elif defined PLATFORM_CYGWIN
  				//TODO: find appropriate method
  				++(*value);
			#else
  				InterlockedIncrement((long*) value);
			#endif
  		}

  		bool static inline decrementInt(uint32* value) {
			#ifdef PLATFORM_UNIX
  				atomic_subtract_int(value, 1);
  				return *value;
			#elif defined PLATFORM_CYGWIN
  				//TODO: find appropriate method
  				return --(*value);
			#else
  				return InterlockedDecrement((long*) value);
			#endif
  		}

  	};

  } // namespace thread
} //namespace sys

using namespace sys::thread;

#endif /*ATOMIC_H_*/
