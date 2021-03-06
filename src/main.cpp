/*--------------------------------------------------------------------------
    DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
    
    File: main.cpp
    Version: 1.0.1
    Copyright: (C) 2012 by Enzo Roberto Verlato
    Contact: enzover@ig.com.br
    All rights reserved.
    
----------------------------------------------------------------------------
    This file is part of the CommandLine Class.
    
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

#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include <string>
#include <vector>

int main() {
    
    using std::cout;
    using std::endl;
    using std::runtime_error;
    using namespace crosslib;
    
    try {
       cout << getExecutablePath() << endl;
        
        vector<string> args = getArguments();
        for ( unsigned i = 0; i < args.size(); ++i ) {
            std::cout << args.at( i ) << std::endl;
        }
        
        cout << fileExists( "test.txt" ) << endl;
        
        return EXIT_SUCCESS;
        
    } catch ( runtime_error &error ) {
        // Custom user messages...
        
        // Log messages...
        cout << "Exception occurred at " << error.what() << endl;
        
        return EXIT_FAILURE;
    }
}
