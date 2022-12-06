#pragma once

namespace AEON
{
    /*  Struct containing command-line arguments passed into AEON.dll 
        Provides an array operator to more easily iterate over arguments */ 
    //struct AEON_DLL ApplicationArguments
    //{
    //            int     count   = 0;
    //            char**  value   = nullptr;
    //    const   char*   operator[]( int index ) const { return value[index]; }
    //};

    class AEON_DLL Arguments
    {
        public:
            Arguments() : m_argc( nullptr ), m_argv( nullptr ) {};
            Arguments( int* argc, char** argv ) : m_argc( argc ), m_argv( argv ){};
            
                    int&    Count()                         { return *m_argc;   }
                    char**  Values()                        { return m_argv;    }
            const   char*   operator[]( size_t i )          { return Count() >= i 
                                                                     ? m_argv[i]
                                                                     : nullptr; }
//                    void    Remove( size_t i, size_t num)
//                            {
//                                if( i >= *m_argc ) return;
//
//                                int 
//                            }

        protected:
            int*    m_argc;
            char**  m_argv;
    };
}