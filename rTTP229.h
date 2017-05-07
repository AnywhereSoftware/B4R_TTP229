#pragma once
#include "B4RDefines.h"
#include "TTP229.h"
//~version: 1.00
namespace B4R {
	//~shortname: TTP229
	//~Event: KeyPressed (Key As Byte)
	class B4RTTP229 {
		private:
			uint8_t be[sizeof(TTP229)];
			TTP229* ttp;
			typedef void (*SubVoidByte)(Byte Key) ;
			SubVoidByte KeyPressedSub;
			bool key8;
			bool noKey;
			static void looper(void* b);
			PollerNode pnode;
			void start();
		public:
			//Initializes the object.
			void Initialize(Byte PinSCL, Byte PinSDO, SubVoidByte KeyPressedSub);
			void Start8Keys();
			void Start16Keys();
	};
}