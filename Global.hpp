#pragma once

#include "Object.hpp"
#include "Class.hpp"
#include "Identifier.hpp"

namespace rb
{
    
    // Modules
    extern Module mKernel;
    extern Module mComparable;
    extern Module mEnumerable;
    extern Module mErrno;
    extern Module mFileTest;
    extern Module mGC;
    extern Module mMath;
    extern Module mProcess;
    extern Module mWaitReadable;
    extern Module mWaitWritable;
    
    // Classes
    extern Class cBasicObject;
    extern Class cObject;
    extern Class cArray;
    extern Class cBignum;
    extern Class cBinding;
    extern Class cClass;
    //extern Class cCont;
    extern Class cDir;
    extern Class cData;
    extern Class cFalseClass;
    extern Class cEncoding;
    extern Class cEnumerator;
    extern Class cFile;
    extern Class cFixnum;
    extern Class cFloat;
    extern Class cHash;
    extern Class cInteger;
    extern Class cIO;
    extern Class cMatch;
    extern Class cMethod;
    extern Class cModule;
    extern Class cNameErrorMesg;
    extern Class cNilClass;
    extern Class cNumeric;
    extern Class cProc;
    extern Class cRandom;
    extern Class cRange;
    extern Class cRational;
    extern Class cComplex;
    extern Class cRegexp;
    extern Class cStat;
    extern Class cString;
    extern Class cStruct;
    extern Class cSymbol;
    extern Class cThread;
    extern Class cTime;
    extern Class cTrueClass;
    extern Class cUnboundMethod;
    
    // Exceptions
    extern Class eException;
    extern Class eStandardError;
    extern Class eSystemExit;
    extern Class eInterrupt;
    extern Class eSignal;
    extern Class eFatal;
    extern Class eArgError;
    extern Class eEOFError;
    extern Class eIndexError;
    extern Class eStopIteration;
    extern Class eKeyError;
    extern Class eRangeError;
    extern Class eIOError;
    extern Class eRuntimeError;
    extern Class eSecurityError;
    extern Class eSystemCallError;
    extern Class eThreadError;
    extern Class eTypeError;
    extern Class eZeroDivError;
    extern Class eNotImpError;
    extern Class eNoMemError;
    extern Class eNoMethodError;
    extern Class eFloatDomainError;
    extern Class eLocalJumpError;
    extern Class eSysStackError;
    extern Class eRegexpError;
    extern Class eEncodingError;
    extern Class eEncCompatError;
    extern Class eScriptError;
    extern Class eNameError;
    extern Class eSyntaxError;
    extern Class eLoadError;
    extern Class eMathDomainError;
    
    // Objects
    extern Object Nil;
    extern Object True;
    extern Object False;
    extern Object Undef;
    
    template<typename... Args>
    inline Object p(Args... args);
    
    template<typename... Args>
    inline Object print(Args... args);
    
    template<typename... Args>
    inline Object puts(Args... args);
    
    template<typename... Args>
    inline Object raise(Args... args);
    
}
