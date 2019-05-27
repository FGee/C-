#ifndef __MEMBER_FUNC_ADDRESS_H__
#define __MEMBER_FUNC_ADDRESS_H__

template<typename dst_type,typename src_type>
dst_type pointer_cast(src_type src)
{
    return *static_cast<dst_type*>(static_cast<void*>(&src));
}

template<typename dst_type,typename src_type>
dst_type union_cast(src_type src)
{
    union{
        src_type s;
        dst_type d;
    }u;
    u.s = src;
    return u.d;
}

//__declspec(naked) void* __cdecl cdecl_cast(...)
//{
//    __asm{
//        mov eax,dword ptr[esp+4]
//        ret
//    }
//}

#define asm_cast(var,addr)  \
{                           \
    __asm{                  \
        mov var,offset addr \
    }                       \
}    
#endif
