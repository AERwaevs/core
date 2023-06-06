#pragma once

namespace aer
{
    /*  Struct containing command-line arguments passed into AEON.dll 
        Provides an array operator to more easily iterate over arguments */ 
    //struct ApplicationArguments
    //{
    //            int     count   = 0;
    //            char**  value   = nullptr;
    //    const   char*   operator[]( int index ) const { return value[index]; }
    //};

    class Arguments
    {
        public:
            Arguments() : _argc( nullptr ), _argv( nullptr ) {};
            Arguments( int* argc, char** argv ) : _argc( argc ), _argv( argv ){};
            
                    int&    Count()                         { return *_argc;   }
                    char**  Values()                        { return _argv;    }
            const   char*   operator[]( size_t i )          { return Count() >= i 
                                                                     ? _argv[i]
                                                                     : nullptr; }
//                    void    Remove( size_t i, size_t num)
//                            {
//                                if( i >= *_argc ) return;
//
//                                int 
//                            }

        protected:
            int*    _argc;
            char**  _argv;
    };
}