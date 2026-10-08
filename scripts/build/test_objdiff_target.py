"""Guard the distinction between function symbols and exported switch labels."""

import unittest

from prepare_objdiff_target import switch_labels


class SwitchLabelTests(unittest.TestCase):
    def test_only_explicit_switch_labels_are_localized(self):
        source = """
glabel SetUp__7CSphidaFi
  jlabel .L002EEA54
glabel .L002EEB18
.L002EEC20:
glabel named_function
jlabel named_function
.word .L002EEA54
"""
        self.assertEqual(switch_labels(source), [".L002EEA54"])

    def test_comments_and_near_matches_are_not_symbols(self):
        source = """
# jlabel .L002EEA54
// jlabel .L002EEB18
jlabel .L002EEA54_suffix
jlabel .L002EEA5
jlabel .L002EEA540
"""
        self.assertEqual(switch_labels(source), [])

    def test_repeated_labels_have_one_metadata_adjustment(self):
        self.assertEqual(switch_labels(
            "  jlabel .L002EEB18\n\tjlabel .L002EEA54\njlabel .L002EEB18\n"),
            [".L002EEA54", ".L002EEB18"])


if __name__ == "__main__":
    unittest.main()
