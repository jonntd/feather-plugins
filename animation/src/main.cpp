/**********************************************************************
 *
 * Filename: main.cpp
 *
 * Description: Plugin contains common animation nodes and commands.
 *
 * Copyright (C) 2015 Richard Layman, rlayman2000@yahoo.com 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#include <feather/deps.hpp>
#include <feather/pluginmanager.hpp>
#include <feather/field.hpp>
#include <feather/node.hpp>
#include <feather/parameter.hpp>
#include <feather/command.hpp>
#include <feather/scenegraph.hpp>
#include <feather/draw.hpp>
#include <QColor>

#ifdef __cplusplus
extern "C" {
#endif
    C_PLUGIN_WRAPPER()
#ifdef __cplusplus
}
#endif

using namespace feather;

#define ANIMATION_KEY 420
#define ANIMATION_KEYTRACK 421

PLUGIN_INIT("Animation","Animation nodes and commands","Richard Layman",ANIMATION_KEY,ANIMATION_KEYTRACK)

/*
 ***************************************
 *            ANIMATION KEY            *
 ***************************************
*/

// parent
ADD_FIELD_TO_NODE(ANIMATION_KEY,FNode,field::Node,field::connection::In,FNode(),1)
// child
ADD_FIELD_TO_NODE(ANIMATION_KEY,FNode,field::Node,field::connection::Out,FNode(),2)

// meshIn
//ADD_FIELD_TO_NODE(ANIMATION_KEY,FMesh,field::Mesh,field::connection::In,FMesh(),3)
// testIn
//ADD_FIELD_TO_NODE(ANIMATION_KEY,FReal,field::Real,field::connection::In,1,4)

namespace feather
{

    DO_IT(ANIMATION_KEY)
    { 
        return status();
    };

    /*
    DRAW_IT(ANIMATION_KEY)
    {
        std::cout << "ANIMATION_KEY DRAW IT\n";
        ADD_MESH(3)
        return status();    
    };
    */

} // namespace feather

// TODO add icon path
NODE_INIT(ANIMATION_KEY,node::Animation,"")


/*
 ***************************************
 *            ANIMATION TRACK          *
 ***************************************
*/
// parent
ADD_FIELD_TO_NODE(ANIMATION_KEYTRACK,FNode,field::Node,field::connection::In,FNode(),1)
// child
ADD_FIELD_TO_NODE(ANIMATION_KEYTRACK,FNode,field::Node,field::connection::Out,FNode(),2)

namespace feather
{

    DO_IT(ANIMATION_KEYTRACK)
    { 
        return status();
    };

} // namespace feather

// TODO add icon path
NODE_INIT(ANIMATION_KEYTRACK,node::Animation,"")


/*
 ***************************************
 *              COMMANDS               *
 ***************************************
*/

namespace feather
{
    namespace command
    {
        enum Command { N=0 };

    } // namespace command

} // namespace feather

INIT_COMMAND_CALLS(N)