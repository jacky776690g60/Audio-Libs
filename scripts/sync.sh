#!/bin/bash

########################################
# No longer used. Just for reference
########################################


echo "Current working directory: $(pwd)"

# Path to the root of the repository
REPO_PATH="."
# name of the folder of temporary repo
TEMP_PUBLIC_DIR="tmp-public-repo"


# Path to temporary directory
TEMP_PUBLIC_PATH="$REPO_PATH/$TEMP_PUBLIC_DIR"



rm -rf "$TEMP_PUBLIC_PATH"    # force delete first if exists
mkdir -p "$TEMP_PUBLIC_PATH"  # recreating


# Ensuring tmp repo is ignored when publishing to private repo
echo "$TEMP_PUBLIC_DIR/" >> "$TEMP_PUBLIC_PATH/.gitignore"


# ========================= Public Repo Processing =============================
# copy files to be shown in the public repo
find "$REPO_PATH" \
  \( -name "Clipping.h" -o -name "SimpleLowPassFilter.h" \) \
  -exec cp --parents {} "$TEMP_PUBLIC_PATH" \;



# copy images to the public repo
# \( \) is necessary for grouping conditions
find "$REPO_PATH" \( \
  -regex ".*\.\(png\|gif\|jpg\|jpeg\)" \
  -o -name "README.md" \
  -o -name "LICENSE" \
  \) \
  -exec cp --parents {} "$TEMP_PUBLIC_PATH" \;

# copy the entire samples folder to temp public folder
cp -r "$REPO_PATH/samples" "$TEMP_PUBLIC_PATH"