#ifndef NODE_DTL_CLASS_H
#define NODE_DTL_CLASS_H

#include <string>
#include <vector>

#include "dtl.h"

class Dtl : ObjectWrap
{
public:
    typedef vector<string> strVec;
    typedef vector<int>    intVec;
    Dtl(const string& a, const string& b)
        : sdiff(new dtl::Diff< char, string >(a, b))
    {
        // do nothing
    }
    
    Dtl(const strVec& a, const strVec& b)
        : vsdiff(new dtl::Diff< string, strVec >(a, b))
    {
        // do nothing
    }
    
    Dtl(const intVec& a, const intVec& b)
        : vidiff(new dtl::Diff< int, intVec >(a, b))
    {
        // do nothing
    }
    
    ~Dtl()
    {
        HandleScope scope;
        run(DtlOperandDestruct, scope);
    }

    static Handle<Value> New(const Arguments& args);
    static Handle<Value> Compose(const Arguments& args);
    static Handle<Value> ComposeUnifiedHunks(const Arguments& args);
    static Handle<Value> Editdistance(const Arguments& args);
    static Handle<Value> Lcs(const Arguments& args);
    static Handle<Value> Ses(const Arguments& args);
    static Handle<Value> SesString(const Arguments& args);
    static Handle<Value> UniHunks(const Arguments& args);
    static Handle<Value> UniHunksString(const Arguments& args);
    static Handle<Value> PrintSes(const Arguments& args);
    static Handle<Value> PrintUnifiedFormat(const Arguments& args);
    void setType(enum arg_type_t type);
    enum arg_type_t getType();
    Handle<Value> run(enum op_t, HandleScope& scope);
private:
    dtl::Diff<char,    string>  *sdiff;
    dtl::Diff<string,  strVec > *vsdiff;
    dtl::Diff<int,     intVec > *vidiff;
    enum arg_type_t type;
};

#endif // NODE_DTL_CLASS_H
