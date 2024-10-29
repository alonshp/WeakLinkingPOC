#https://stackoverflow.com/questions/35655698/how-to-archive-an-app-that-includes-a-custom-framework/35703033#35703033

# Merge Script

# 1
# Set bash script to exit immediately if any commands fail.
set -e
set +u


# 2
# Setup some constants for use later on.
CONFIGURATION=$1
SRCROOT=`pwd`
WORKSPACE="weakLinkingPOC.xcworkspace"
TARGET_NAME="weakLinkingPOCSDK"
FRAMEWORK_NAME="weakLinkingPOCSDK"
BUILD_DIR="${SRCROOT}/build"
RELEASE_DIR="${SRCROOT}/Release/"




# If remnants from a previous build exist, delete them.
if [ -d "${SRCROOT}/build" ]; then
rm -rf "${SRCROOT}/build"
fi

if [ -d "${SRCROOT}/Release" ]; then
rm -rf "${SRCROOT}/Release"
fi

mkdir "${SRCROOT}/Release"

# https://medium.com/@er.mayursharma14/how-to-create-xcframework-855817f854cf

# Build the framework for device and for simulator (using
# all needed architectures).
xcodebuild archive -workspace "${WORKSPACE}" -scheme "${TARGET_NAME}" -configuration "${CONFIGURATION}" -destination="iOS" -sdk iphonesimulator SKIP_INSTALL=NO SWIFT_SERIALIZE_DEBUGGING_OPTIONS=NO BUILD_LIBRARY_FOR_DISTRIBUTION=YES -archivePath "${BUILD_DIR}/Release-iphonesimulator"
xcodebuild archive -workspace "${WORKSPACE}" -scheme "${TARGET_NAME}" -configuration "${CONFIGURATION}" -destination="iOS" -sdk iphoneos        SKIP_INSTALL=NO SWIFT_SERIALIZE_DEBUGGING_OPTIONS=NO BUILD_LIBRARY_FOR_DISTRIBUTION=YES -archivePath "${BUILD_DIR}/Release-iphoneos"



ls -l "${BUILD_DIR}/"

# https://developer.apple.com/forums/thread/655768

# First, get all the UUID filepaths for BCSymbolMaps, because these are randomly generated and need to be individually added as the `-debug-symbols` parameter. The dSYM path is always the same so that one is manually added
#echo "XCFramework: Generating IPHONE BCSymbolMap paths..."
#IPHONE_BCSYMBOLMAP_PATHS=(${BUILD_DIR}/Release-iphoneos.xcarchive/BCSymbolMaps/*)
#IPHONE_BCSYMBOLMAP_COMMANDS=""
#for path in "${IPHONE_BCSYMBOLMAP_PATHS[@]}"; do
#  IPHONE_BCSYMBOLMAP_COMMANDS="$IPHONE_BCSYMBOLMAP_COMMANDS -debug-symbols $path "
#  echo $IPHONE_BCSYMBOLMAP_COMMANDS
#done
#
#echo "XCFramework: Generating IPHONE BCSymbolMap paths... --> Done"

echo "Creating XCFramework..."

# XCFramework with debug symbols - see https://pspdfkit.com/blog/2021/advances-in-xcframeworks/#built-in-support-for-bcsymbolmaps-and-dsyms
xcodebuild -create-xcframework -allow-internal-distribution \
    -framework "${SRCROOT}/build/Release-iphoneos.xcarchive/Products/Library/Frameworks/${FRAMEWORK_NAME}.framework" \
    -debug-symbols "${SRCROOT}/build/Release-iphoneos.xcarchive/dSYMs/${FRAMEWORK_NAME}.framework.dSYM" \
    $IPHONE_BCSYMBOLMAP_COMMANDS \
    -framework "${SRCROOT}/build/Release-iphonesimulator.xcarchive/Products/Library/Frameworks/${FRAMEWORK_NAME}.framework" \
    -debug-symbols "${SRCROOT}/build/Release-iphonesimulator.xcarchive/dSYMs/${FRAMEWORK_NAME}.framework.dSYM" \
    -output "${RELEASE_DIR}/${FRAMEWORK_NAME}.xcframework"

echo "Creating XCFramework... --> Done"



# 9
# Delete the most recent build.
if [ -d "${SRCROOT}/build" ]; then
rm -rf "${SRCROOT}/build"
fi
