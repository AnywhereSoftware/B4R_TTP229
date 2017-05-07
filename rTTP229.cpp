
#include "B4RDefines.h"
namespace B4R {
	
	void B4RTTP229::Initialize(Byte PinSCL, Byte PinSDO, SubVoidByte KeyPressedSub) {
		ttp = new (be) TTP229(PinSCL, PinSDO);
		this->KeyPressedSub = KeyPressedSub;
		noKey = true;
	}
	void B4RTTP229::Start8Keys() {
		key8 = true;
		start();
	}
	void B4RTTP229::Start16Keys() {
		key8 = false;
		start();
	}
	void B4RTTP229::start() {
		FunctionUnion fu;
		fu.PollerFunction = looper;
		pnode.functionUnion = fu;
		pnode.tag = this;
		if (pnode.next == NULL) {
			pollers.add(&pnode);
		}
	}
	
	//static
	void B4RTTP229::looper(void* b) {
		B4RTTP229* me = (B4RTTP229*) b;
		Byte c;
		if (me->key8)
			c = me->ttp->GetKey8();
		else
			c = me->ttp->GetKey16();
		if (c) {
			if (me->noKey) {
				me->noKey = false;
				me->KeyPressedSub(c);
			}
		} else {
			me->noKey = true;
		}
		
	}
};

