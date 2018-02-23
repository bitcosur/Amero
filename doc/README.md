Amero Core 0.12.1
=====================

This is the official reference wallet for Amero digital currency and comprises the backbone of the Amero peer-to-peer network. You can [download Amero Core](https://www.amero.org/downloads/) or [build it yourself](#building) using the guides below.

Running
---------------------
The following are some helpful notes on how to run Amero on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/amero-qt` (GUI) or
- `bin/amerod` (headless)

### Windows

Unpack the files into a directory, and then run amero-qt.exe.

### OS X

Drag Amero-Qt to your applications folder, and then run Amero-Qt.

### Need Help?

* See the [Amero documentation](https://ameropay.atlassian.net/wiki/display/DOC)
for help and more information.
* Ask for help on [#ameropay](http://webchat.freenode.net?channels=ameropay) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=ameropay).
* Ask for help on the [AmeroTalk](https://amerotalk.org/) forums.

Building
---------------------
The following are developer notes on how to build Amero Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Amero Core repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- Source Code Documentation ***TODO***
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Unit Tests](unit-tests.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)

### Resources
* Discuss on the [AmeroTalk](https://amerotalk.org/) forums, in the Development & Technical Discussion board.
* Discuss on [#ameropay](http://webchat.freenode.net/?channels=ameropay) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=ameropay).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
