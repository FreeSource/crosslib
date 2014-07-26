/*--------------------------------------------------------------------------
    DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
    
    File: system.cpp
    Version: 2.0.0
    Copyright: (C) 2012 by Enzo Roberto Verlato
    Contact: enzover@ig.com.br
    All rights reserved.
    
----------------------------------------------------------------------------
    This file is part of the compatibility library.
    
    This file may be used under the terms of the GNU General Public
    License version 2.0 as published by the Free Software Foundation
    and appearing in the file LICENSE.GPL2 included in the packaging of
    this file.
    
    This file is provided "AS IS" in the hope that it will be useful,
    but WITHOUT ANY WARRANTY OF ANY KIND, INCLUDING THE WARRANTIES OF DESIGN;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
    PARTICULAR PURPOSE. See the GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
--------------------------------------------------------------------------*/

#include <system.h>

#include <stdexcept>

#include <Application.h>
#include <Path.h>
#include <Roster.h>

namespace {
    
    using std::runtime_error;
    
    string executablepath;
    vector<string> arguments;
    
    class App : public BApplication {
        public:
            App();
            virtual void ArgvReceived( int32 argc, char** argv );
            void ReadyToRun();
    };
    
    App::App() : BApplication( "application/x-vnd.lh-App" ) {
        app_info info;
        be_app->GetAppInfo( &info );
        BEntry entry( &info.ref );
        BPath path;
        entry.GetPath( &path );
        executablepath = path.Path();
    }
    
    void App::ArgvReceived( int32 argc, char** argv ) {
        for ( int32 i = 1; i < argc; ++i ) {
            arguments.push_back( argv[i] );
        }
    }
    
    void App::ReadyToRun() {
        Quit();
    }
    
    void createApp() {
        App app;
        app.Run();
    }
}

namespace crosslib {
    
    const string getExecutablePath() {
        if ( executablepath.empty() ) {
            createApp();
        }
        return executablepath;
    }
    
    const vector<string> getArguments() {
        if ( arguments.empty() ) {
            createApp();
        }
        return arguments;
    }
    
    const string getCurrentDirectory() {
        char currentDir[PATH_MAX];
        
        if ( getcwd( currentDir, PATH_MAX ) != NULL ) {
            return currentDir;
        } else {
            throw runtime_error( "FILE: " + string( __FILE__ ) + " FUNCTION: " + string( __PRETTY_FUNCTION__ ) + " -> " + "Can't get process current working directory." );
        }
    }
}