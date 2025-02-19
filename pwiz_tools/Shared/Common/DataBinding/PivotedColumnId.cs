﻿/*
 * Original author: Nicholas Shulman <nicksh .at. u.washington.edu>,
 *                  MacCoss Lab, Department of Genome Sciences, UW
 *
 * Copyright 2020 University of Washington - Seattle, WA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace pwiz.Common.DataBinding
{
    /// <summary>
    /// Identifies a column which is part of a group of related columns which have been pivoted together.
    /// </summary>
    public class PivotedColumnId
    {
        public PivotedColumnId(object pivotKey, IColumnCaption pivotKeyCaption, object seriesId, IColumnCaption seriesCaption)
        {
            PivotKey = pivotKey;
            PivotKeyCaption = pivotKeyCaption;
            SeriesId = seriesId;
            SeriesCaption = seriesCaption;
        }

        public object PivotKey { get; }
        public IColumnCaption PivotKeyCaption { get; }

        public object SeriesId { get; }

        public IColumnCaption SeriesCaption { get; }
    }
}
