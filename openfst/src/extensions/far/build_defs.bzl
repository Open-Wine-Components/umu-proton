# Copyright 2005-2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the 'License');
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an 'AS IS' BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
"""Helper library to define BUILD rules for FAR manipulation."""

def convert_far_types(name, far_in, far_out, far_type = None, fst_type = None, **kwds):
    """Converts the FAR type and/or FST types in a FAR, writing a new FAR.

    Args:
      name: The BUILD rule name.
      far_in: The input FAR file.
      far_out: The output FAR file with converted FST types.
      far_type: An optional string specifying the desired type of the FAR in far_out.
                If None, the input FAR's type will be used.
      fst_type: An optional string specifying the desired type of the FSTs in far_out.
                If None, each FST will retain its input type.
      **kwds: Attributes common to all BUILD rules, e.g., testonly, visibility.
    """

    farconvert_rule = "@org_openfst//:farconvert"
    farconvert_cmd = "$(location %s) " % farconvert_rule
    if not far_type and not fst_type:
        fail("No-op conversion for FAR %s." % far_in)
    if far_type:
        farconvert_cmd += " --far_type=%s" % far_type
    if fst_type:
        farconvert_cmd += " --fst_type=%s" % fst_type
    farconvert_cmd += " $(location %s)" % far_in
    farconvert_cmd += " $(location %s)" % far_out

    native.genrule(
        name = name,
        srcs = [far_in],
        exec_tools = [farconvert_rule],
        outs = [far_out],
        cmd = farconvert_cmd,
        message = "Converting FST type in FAR %s ==> %s" % (far_in, far_out),
        **kwds
    )
