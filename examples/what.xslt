<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  <xsl:template match="*">
    <node id="{generate-id()}" label="{name()}"/>
    <edge from="{generate-id(..)}" to="{generate-id()}"/>
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="text()">
    <node id="{generate-id()}" label="{.}"/>
    <edge from="{generate-id(..)}" to="{generate-id()}"/>
  </xsl:template>
</xsl:stylesheet>
