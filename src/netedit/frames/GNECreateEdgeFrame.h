/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2020 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GNECreateEdgeFrame.h
/// @author  Pablo Alvarez Lopez
/// @date    Dec 2018
///
// The Widget for create edges (and junctions)
/****************************************************************************/
#pragma once
#include "GNEFrame.h"


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class GNECreateEdgeFrame
 * The Widget for create edges
 */
class GNECreateEdgeFrame : public GNEFrame {
    /// @brief FOX-declaration
    FXDECLARE(GNECreateEdgeFrame)

public:
    /**@brief Constructor
     * @brief parent FXHorizontalFrame in which this GNEFrame is placed
     * @brief viewNet viewNet that uses this GNEFrame
     */
    GNECreateEdgeFrame(FXHorizontalFrame* horizontalFrameParent, GNEViewNet* viewNet);

    /// @brief Destructor
    ~GNECreateEdgeFrame();

    /**@brief handle processClick and set the relative colouring
     * @param[in] clickedPosition clicked position over ViewNet
     * @param objectsUnderCursor collection of objects under cursor after click over view (note: in this case use non-constant reference due setCreatedJunction)
     * @param objectsUnderGrippedCursor collection of objects under gripped cursor after click over view (note: in this case use non-constant reference due setCreatedJunction)
     * @param oppositeEdge automatically create an opposite edge
     * @param chainEdge create edges in chain mode
     */
    void processClick(const Position& clickedPosition, GNEViewNetHelper::ObjectsUnderCursor& objectsUnderCursor,
                      GNEViewNetHelper::ObjectsUnderCursor& objectsUnderGrippedCursor, const bool oppositeEdge, const bool chainEdge);

    /// @brief abort current edge creation
    void abortEdgeCreation();

    /// @brief show prohibition frame
    void show();

    /// @brief hide prohibition frame
    void hide();

    /// @name FOX-callbacks
    /// @{
    /// @brief Called when the user presses the OK-Button saves any edge modifications
    long onCmdOK(FXObject*, FXSelector, void*);

    /// @brief Called when the user presses the Cancel-button discards any edge modifications
    long onCmdCancel(FXObject*, FXSelector, void*);

protected:
    FOX_CONSTRUCTOR(GNECreateEdgeFrame)

private:
    /// @brief source junction for new edge
    GNEJunction* myCreateEdgeSource;
};
