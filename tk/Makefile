##
# Makefile for Tk
##
# Daniel A. Steffen <das@users.sourceforge.net>:
##

# Project info
Project               = tk
ProjectName           = Tk
UserType              = Developer
ToolType              = Commands

# Fetch info
Release               = 8.5.9
UrlFile               = $(Project)$(Release)
Url                   = http://cloud.github.com/downloads/das/tcltk/$(UrlFile)-decarbon$(UrlExt)

Configure             = $(Sources)/unix/configure
Extra_Environment     = INSTALL_PATH="$(NSFRAMEWORKDIR)" PREFIX="$(USRDIR)" \
                        APPLICATION_INSTALL_PATH="$(AppInstallDir)" \
			SYMROOT="$(SYMROOT)" OBJROOT="$(OBJROOT)" \
			MANDIR="$(MANDIR)" INSTALL_MANPAGES=1 \
			EXTRA_CONFIGURE_ARGS="$(Configure_Flags)" \
			TCL_FRAMEWORK_DIR="$(TclFrameworkDir)" TCLSH_DIR="$(TclshDir)"
AfterInstall          = extra-int-headers lipo links compress_man_pages fix-perms remove-html-docs

include $(MAKEFILEPATH)/CoreOS/ReleaseControl/Common.make
include ../tcl_ext/Fetch.make

Install_Flags         = INSTALL_ROOT="$(DSTROOT)"

Version               = $(shell $(GREP) "TK_VERSION=" "$(Configure)" | $(CUT) -d '=' -f 2)

FmwkDir               = $(NSFRAMEWORKDIR)/Tk.framework/Versions/$(Version)
LibItems              = tkConfig.sh libtkstub$(Version).a
HeaderItems           = tk.h tkDecls.h tkPlatDecls.h tkIntXlibDecls.h tkMacOSX.h
PrivateHeaderItems    = tkInt.h tkIntDecls.h tkIntPlatDecls.h tkMacOSXInt.h \
                        tkPort.h tkMacOSXPort.h ttkDecls.h ttkTheme.h \
                        default.h tkMacOSXDefault.h tkFont.h
AppInstallDir         = $(NSDEVELOPERAPPSDIR)/Utilities

Tclsh                 = $(USRBINDIR)/tclsh
TclFramework          = $(NSFRAMEWORKDIR)/Tcl.framework

TclshDir              = $(shell dirname $(Tclsh))
TclFrameworkDir       = $(shell dirname $(TclFramework))

Wish_app              = Wish.app
Wish_bin              = $(Wish_app)/Contents/MacOS/Wish

# add suffix to tk manpage names to avoid conflicts
Manpage_Suffix        = tcl
Configure_Flags       += --enable-man-suffix=$(Manpage_Suffix)

extra-int-headers:
	$(_v) $(INSTALL_FILE) "$(Sources)/generic/default.h" "$(Sources)/macosx/tkMacOSXDefault.h" \
	        "$(Sources)/generic/tkFont.h" "$(DSTROOT)$(FmwkDir)/PrivateHeaders"
	$(_v) $(MKDIR) "$(DSTROOT)$(FmwkDir)/Headers/tk-private"
	$(_v) $(MV) -f $(foreach f,$(PrivateHeaderItems),"$(DSTROOT)$(FmwkDir)/PrivateHeaders/$(f)") "$(DSTROOT)$(FmwkDir)/Headers/tk-private"
	$(_v) $(RMDIR) "$(DSTROOT)$(FmwkDir)/PrivateHeaders"
	$(_v) $(LN) -fsh "Headers/tk-private" "$(DSTROOT)$(FmwkDir)/PrivateHeaders"

lipo_archs := $(filter ppc,$(RC_ARCHS))
ifdef lipo_archs
define lipo
	$(_v) lipo $(patsubst %,-remove %,$(patsubst ppc,ppc7400,$(lipo_archs))) -output $(1) $(1)
endef
endif
lipo:
	$(call lipo,$(DSTROOT)$(FmwkDir)/Resources/$(Wish_bin))

links:
	$(_v) $(INSTALL_DIRECTORY) "$(DSTROOT)$(USRLIBDIR)"
	$(_v) $(LN) -fs "../..$(FmwkDir)/$(ProjectName)" "$(DSTROOT)$(USRLIBDIR)/libtk$(Version).dylib"
	$(_v) $(LN) -fs "libtk$(Version).dylib" "$(DSTROOT)$(USRLIBDIR)/libtk.dylib"
	$(_v) $(LN) -fs $(foreach f,$(LibItems),"../..$(FmwkDir)/$(f)") "$(DSTROOT)$(USRLIBDIR)"
	$(_v) $(INSTALL_DIRECTORY) "$(DSTROOT)$(USRINCLUDEDIR)"
	$(_v) $(LN) -fs $(foreach f,$(HeaderItems),"../..$(FmwkDir)/Headers/$(f)") \
	        "$(DSTROOT)$(USRINCLUDEDIR)"
# Install compat sym links for private headers in /usr/local/include
	$(_v) $(INSTALL_DIRECTORY) "$(DSTROOT)$(USRDIR)/local/include"
	$(_v) $(LN) -fs $(foreach f,$(PrivateHeaderItems),"../../..$(FmwkDir)/Headers/tk-private/$(f)") \
	        "$(DSTROOT)$(USRDIR)/local/include/"
# Move wish.1 to wish$(Version).1 and link wish.1 to wish$(Version).1
	$(_v) $(MV) -f "$(DSTROOT)$(MANDIR)/man1/wish.1$(Manpage_Suffix)" \
	        "$(DSTROOT)$(MANDIR)/man1/wish$(Version).1$(Manpage_Suffix)"
	$(_v) $(LN) -fs "wish$(Version).1$(Manpage_Suffix)" \
	        "$(DSTROOT)$(MANDIR)/man1/wish.1$(Manpage_Suffix)"

fix-perms:
	$(_v)- $(CHOWN) -R $(Install_User):$(Install_Group) $(DSTROOT)
	$(_v)- $(FIND) $(DSTROOT) -type f ! -perm -+x ! -perm $(Install_File_Mode) -print0 | $(XARGS) -0 $(CHMOD) $(Install_File_Mode)
	$(_v)- $(FIND) $(DSTROOT) -type f -perm -+x ! -perm $(Install_Program_Mode) -print0 | $(XARGS) -0 $(CHMOD) $(Install_Program_Mode)
	$(_v)- $(FIND) $(DSTROOT) -type d ! -perm $(Install_Directory_Mode) -print0 | $(XARGS) -0 $(CHMOD) $(Install_Directory_Mode)

remove-html-docs:
	$(_v) $(RM) -rf $(DSTROOT)$(FmwkDir)/Resources/Documentation

###

Sources               = $(SRCROOT)/$(Project)
MakeDir               = $(Sources)/macosx

Fmwk                  = $(SYMROOT)/$(ProjectName).framework
BuildTarget           = $(Project) BUILD_STYLE=Deployment
InstallTarget         = install-deploy

all: build

build:: $(Fmwk) $(Fmwk).dSYM

$(Fmwk):
	@echo "Building $(Project)..."
	$(_v) $(Environment) $(MAKE) -C $(MakeDir) $(BuildTarget)

$(Fmwk).dSYM: $(Fmwk)
	$(_v) $(DSYMUTIL) -o $(Fmwk).dSYM $(Fmwk)/$(ProjectName)
	$(call lipo,$(SYMROOT)/$(Wish_bin))
	$(_v) $(DSYMUTIL) -o $(SYMROOT)/$(Wish_app).dSYM $(SYMROOT)/$(Wish_bin)

install:: $(Fmwk) $(Fmwk).dSYM
	@echo "Installing $(Project)..."
	-@$(RM) -f "$(DSTROOT)$(FmwkDir)/PrivateHeaders"
	$(_v) umask $(Install_Mask) ; $(Environment) $(MAKE) -C $(MakeDir) \
	        $(Install_Flags) $(InstallTarget)
	$(_v) $(RMDIR) $(DSTROOT)$(NSDEVELOPERAPPSDIR)
	$(_v) $(FIND) $(DSTROOT) $(Find_Cruft) -print0 | $(XARGS) -0 $(RMDIR)
	$(_v) $(MAKE) $(AfterInstall)

almostclean::
	@echo "Cleaning $(Project)..."
	$(_v) $(Environment) $(MAKE) -C $(MakeDir) clean-$(BuildTarget)

.PHONY: almostclean $(AfterInstall)
